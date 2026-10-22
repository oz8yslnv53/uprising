#!/usr/bin/env python3
"""Check that the generated public ByteMatch report reflects its inventories."""

import argparse
import csv
import json
from pathlib import Path


def load_rows(path):
    with path.open(newline="") as handle:
        return list(csv.DictReader(handle, delimiter="\t"))


def expect(label, actual, expected):
    if actual != expected:
        raise ValueError(f"{label}: got {actual!r}, expected {expected!r}")


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--report", type=Path, required=True)
    parser.add_argument("--catalog", type=Path, default=Path("data/functions.tsv"))
    parser.add_argument("--data", type=Path, default=Path("data/data.tsv"))
    parser.add_argument("--units", type=Path, default=Path("data/function_units.tsv"))
    args = parser.parse_args()

    functions = [row for row in load_rows(args.catalog) if row["kind"] == "FUNCTION"]
    data = load_rows(args.data)
    unit_rows = load_rows(args.units)
    report = json.loads(args.report.read_text())
    measures = report["measures"]

    exact = [
        row for row in functions
        if row["match_score"] not in ("", "-")
        and float(row["match_score"]) == 100.0
    ]
    expect("function-unit map size", len(unit_rows), len(functions))
    expect("function-unit map addresses", len({row["address"] for row in unit_rows}),
           len(functions))
    expect("total functions", measures["total_functions"], len(functions))
    expect("matched functions", measures["matched_functions"], len(exact))
    expect("total code", measures["total_code"],
           sum(int(row["size"]) for row in functions))
    expect("matched code", measures["matched_code"],
           sum(int(row["size"]) for row in exact))
    expect("total data", measures["total_data"],
           sum(int(row["size"]) for row in data))
    expect("matched data", measures["matched_data"], 0)
    expect("fully linked code", measures["complete_code"], 0)
    expect("fully linked data", measures["complete_data"], 0)
    expect("fully linked units", measures["complete_units"], 0)
    expect("unit count", measures["total_units"], len(report["units"]))
    expect("unit function total", sum(
        unit["measures"]["total_functions"] for unit in report["units"]
    ), len(functions))
    expect("unit exact-match total", sum(
        unit["measures"]["matched_functions"] for unit in report["units"]
    ), len(exact))
    if any(unit["metadata"].get("complete") for unit in report["units"]):
        raise ValueError("a public archive unit was marked fully linked")
    print("ByteMatch report invariants passed")


if __name__ == "__main__":
    main()
