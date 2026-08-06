#!/usr/bin/env python3
"""Generate an objdiff-compatible decomp.dev progress report."""

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


def build_report(catalog_path, data_path):
    rows = load_rows(catalog_path)
    items = []
    data_size = (sum(int(row["size"]) for row in load_rows(data_path))
                 if data_path.exists() else 0)
    total_code = matched_code = fuzzy_code = 0
    matched_functions = 0
    complete_code = 0
    for row in rows:
        address = row["address"].lower()
        size = int(row["size"])
        if row["kind"] == "DATA":
            continue
        score = (float(row["match_score"])
                 if row["match_score"] not in ("", "-") else 0.0)
        total_code += size
        fuzzy_code += size * score / 100.0
        if score == 100.0:
            matched_code += size
            matched_functions += 1
        if row["src_file"] not in ("", "-"):
            complete_code += size
        items.append({
            "name": row["name"],
            "size": size,
            "fuzzy_match_percent": score,
            "metadata": {"virtual_address": int(address, 16)},
        })
    progress = measures(
        total_code, matched_code, fuzzy_code, len(items),
        matched_functions, complete_code, data_size,
    )
    unit = {
        "name": "jp_rev1/code",
        "measures": progress,
        "functions": items,
        "sections": [{
            "name": "Ghidra data labels",
            "size": data_size,
            "fuzzy_match_percent": 0.0,
        }],
        "metadata": {
            "complete": False,
            "progress_categories": ["game"],
        },
    }
    return {
        "measures": progress,
        "units": [unit],
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
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(
        build_report(args.catalog, args.data), indent=2
    ) + "\n")


if __name__ == "__main__":
    main()
