#!/usr/bin/env python3
"""Generate an objdiff-compatible ByteMatch progress report."""

import argparse
import csv
import json
from pathlib import Path


def load_rows(path):
    with path.open(newline="") as handle:
        return list(csv.DictReader(handle, delimiter="\t"))


def measures(total_code, matched_code, fuzzy_code, total_functions,
             matched_functions, complete_code, total_data, matched_data=0,
             complete_data=0, total_units=1, complete_units=0):
    return {
        "fuzzy_match_percent": 100.0 * fuzzy_code / total_code if total_code else 0.0,
        "total_code": total_code,
        "matched_code": matched_code,
        "matched_code_percent": 100.0 * matched_code / total_code if total_code else 0.0,
        "total_functions": total_functions,
        "matched_functions": matched_functions,
        "matched_functions_percent": (100.0 * matched_functions / total_functions
                                       if total_functions else 0.0),
        "complete_code": complete_code,
        "complete_code_percent": (100.0 * complete_code / total_code
                                   if total_code else 0.0),
        "total_data": total_data,
        "matched_data": matched_data,
        "matched_data_percent": (100.0 * matched_data / total_data
                                  if total_data else 0.0),
        "complete_data": complete_data,
        "complete_data_percent": (100.0 * complete_data / total_data
                                   if total_data else 0.0),
        "total_units": total_units,
        "complete_units": complete_units,
    }


def report_item(row):
    address = int(row["address"], 16)
    score = (float(row["match_score"])
             if row["match_score"] not in ("", "-") else 0.0)
    return {
        "name": row["name"],
        "size": int(row["size"]),
        "fuzzy_match_percent": score,
        "metadata": {"virtual_address": address},
    }


def load_units(path):
    with path.open(newline="") as handle:
        rows = csv.DictReader(handle, delimiter="\t")
        expected = ("address", "unit")
        if tuple(rows.fieldnames or ()) != expected:
            raise ValueError(f"unexpected unit map schema: {path}")
        return {row["address"].lower(): row["unit"] for row in rows}


def progress_for_items(items, total_data=0, complete_code=0, total_units=1):
    total_code = sum(item["size"] for item in items)
    matched_items = [item for item in items
                     if item["fuzzy_match_percent"] == 100.0]
    matched_code = sum(item["size"] for item in matched_items)
    fuzzy_code = sum(item["size"] * item["fuzzy_match_percent"] / 100.0
                     for item in items)
    return measures(
        total_code, matched_code, fuzzy_code, len(items), len(matched_items),
        complete_code, total_data, total_units=total_units,
    )


def build_report(catalog_path, data_path, units_path):
    rows = load_rows(catalog_path)
    unit_map = load_units(units_path)
    data_size = (sum(int(row["size"]) for row in load_rows(data_path))
                 if data_path.exists() else 0)
    unit_items = {}
    unit_complete_code = {}
    for row in rows:
        if row["kind"] == "DATA":
            continue
        address = int(row["address"], 16)
        name = "jp_rev1/" + unit_map.get(f"{address:08x}", "unknown")
        unit_items.setdefault(name, []).append(report_item(row))
        if row["src_file"] not in ("", "-"):
            unit_complete_code[name] = unit_complete_code.get(name, 0) + int(row["size"])

    units = []
    for name, items in sorted(unit_items.items()):
        unit = {
            "name": name,
            "measures": progress_for_items(
                items, complete_code=unit_complete_code.get(name, 0),
            ),
            "functions": items,
            "metadata": {
                "complete": False,
                "progress_categories": ["game"],
            },
        }
        units.append(unit)

    progress = progress_for_items(
        [item for items in unit_items.values() for item in items], data_size,
        sum(unit_complete_code.values()), total_units=len(units),
    )
    return {
        "measures": progress,
        "units": units,
        "version": 2,
        "categories": [{
            "id": "game",
            "name": "Game",
            "measures": progress,
        }],
    }


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--catalog", type=Path, default=Path("data/functions.tsv"))
    parser.add_argument("--data", type=Path, default=Path("data/data.tsv"))
    parser.add_argument("--units", type=Path, default=Path("data/function_units.tsv"))
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(
        build_report(args.catalog, args.data, args.units), indent=2
    ) + "\n")


if __name__ == "__main__":
    main()
