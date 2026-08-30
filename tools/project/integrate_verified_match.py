#!/usr/bin/env python3

from __future__ import annotations

import argparse
import csv
import json
import re
import sys
from pathlib import Path
from typing import Any

from function_inventory import FIELDS, load_inventory
from workspace import WorkspaceError, require_workspace_root, resolve_within


class IntegrationError(RuntimeError):
    pass


SYMBOL_PATTERN = re.compile(r"\bfunc_[0-9A-Fa-f]{8}\b")


def parse_address(value: str) -> int:
    try:
        return int(value, 0)
    except ValueError as error:
        raise IntegrationError(f"invalid function address: {value}") from error


def load_json(path: Path) -> dict[str, Any]:
    with path.open("r", encoding="utf-8") as handle:
        value = json.load(handle)
    if not isinstance(value, dict) or value.get("schema") != 1:
        raise IntegrationError(f"{path}: unsupported schema")
    return value


def require_matched_attempt(path: Path, address: int) -> None:
    with path.open("r", encoding="utf-8", newline="") as handle:
        reader = csv.DictReader(handle)
        rows = [
            row
            for row in reader
            if parse_address(row["address"]) == address
        ]
    if not rows or rows[-1]["result"] != "matched":
        raise IntegrationError(
            f"{address:#010x}: latest recorded attempt is not matched"
        )


def write_json(path: Path, value: dict[str, Any]) -> Path:
    temporary = path.with_name(f"{path.name}.tmp")
    temporary.write_text(
        json.dumps(value, indent=2, sort_keys=True) + "\n",
        encoding="utf-8",
    )
    return temporary


def write_inventory(path: Path, rows: list[dict[str, str]]) -> Path:
    temporary = path.with_name(f"{path.name}.tmp")
    with temporary.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=FIELDS, lineterminator="\n")
        writer.writeheader()
        writer.writerows(rows)
    return temporary


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Promote one logged and byte-verified function to matching C."
    )
    parser.add_argument("address", help="function address such as 0x80012345")
    parser.add_argument(
        "--source",
        required=True,
        help="verified temporary C source beneath tmp/",
    )
    parser.add_argument(
        "--destination",
        required=True,
        help="new tracked C source path beneath src/",
    )
    parser.add_argument(
        "--profile",
        required=True,
        help="compiler profile from compiler_profiles.json",
    )
    parser.add_argument(
        "--note",
        required=True,
        help="durable inventory note",
    )
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    temporary_paths: list[Path] = []
    try:
        root = require_workspace_root()
        address = parse_address(args.address)
        source = resolve_within(root, args.source, must_exist=True)
        destination = resolve_within(root, args.destination)
        source_root = resolve_within(root, "src", must_exist=True)
        temporary_root = resolve_within(root, "tmp", must_exist=True)
        try:
            source.relative_to(temporary_root)
        except ValueError as error:
            raise IntegrationError("verified source must be beneath tmp/") from error
        try:
            destination.relative_to(source_root)
        except ValueError as error:
            raise IntegrationError("destination must be beneath src/") from error
        if destination.exists():
            raise IntegrationError(f"destination already exists: {destination}")

        functions_path = resolve_within(
            root, "config/slus_01411/functions.csv", must_exist=True
        )
        attempts_path = resolve_within(
            root, "config/slus_01411/attempts.csv", must_exist=True
        )
        matching_path = resolve_within(
            root, "config/slus_01411/matching_c.json", must_exist=True
        )
        profiles_path = resolve_within(
            root,
            "config/slus_01411/compiler_profiles.json",
            must_exist=True,
        )

        require_matched_attempt(attempts_path, address)
        profiles = load_json(profiles_path).get("profiles")
        if not isinstance(profiles, dict) or args.profile not in profiles:
            raise IntegrationError(f"unknown compiler profile: {args.profile}")

        functions = load_inventory(functions_path)
        matches = [
            function for function in functions if function.address == address
        ]
        if len(matches) != 1:
            raise IntegrationError(
                f"{address:#010x}: expected one inventory function"
            )
        function = matches[0]
        if function.status == "matching_c":
            raise IntegrationError(f"{address:#010x}: already matching C")

        source_text = source.read_text(encoding="utf-8")
        symbols = set(SYMBOL_PATTERN.findall(source_text))
        if function.name not in symbols:
            raise IntegrationError(
                f"{source}: does not define expected symbol {function.name}"
            )
        if not source_text.endswith("\n"):
            source_text += "\n"

        matching = load_json(matching_path)
        entries = matching.get("functions")
        if not isinstance(entries, list):
            raise IntegrationError(f"{matching_path}: functions must be a list")
        if any(
            parse_address(str(entry.get("address"))) == address
            for entry in entries
            if isinstance(entry, dict)
        ):
            raise IntegrationError(f"{address:#010x}: already in matching manifest")
        entries.append(
            {
                "address": f"0x{address:08X}",
                "size": f"0x{function.size:X}",
                "source": str(destination.relative_to(root)),
                "profile": args.profile,
            }
        )
        entries.sort(key=lambda entry: parse_address(str(entry["address"])))

        inventory_rows: list[dict[str, str]] = []
        with functions_path.open("r", encoding="utf-8", newline="") as handle:
            reader = csv.DictReader(handle)
            for row in reader:
                if parse_address(row["address"]) == address:
                    row["status"] = "matching_c"
                    row["notes"] = args.note
                inventory_rows.append(row)

        destination.parent.mkdir(parents=True, exist_ok=True)
        source_temporary = destination.with_name(f"{destination.name}.tmp")
        source_temporary.write_text(source_text, encoding="utf-8")
        temporary_paths.append(source_temporary)
        matching_temporary = write_json(matching_path, matching)
        temporary_paths.append(matching_temporary)
        inventory_temporary = write_inventory(functions_path, inventory_rows)
        temporary_paths.append(inventory_temporary)

        source_temporary.replace(destination)
        temporary_paths.remove(source_temporary)
        matching_temporary.replace(matching_path)
        temporary_paths.remove(matching_temporary)
        inventory_temporary.replace(functions_path)
        temporary_paths.remove(inventory_temporary)
    except (
        IntegrationError,
        WorkspaceError,
        OSError,
        UnicodeError,
        KeyError,
        TypeError,
        ValueError,
        csv.Error,
        json.JSONDecodeError,
    ) as error:
        for path in temporary_paths:
            path.unlink(missing_ok=True)
        print(f"error: {error}", file=sys.stderr)
        return 1

    print(
        f"integrated: {address:#010x} -> "
        f"{destination.relative_to(root)}"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
