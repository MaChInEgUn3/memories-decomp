#!/usr/bin/env python3

from __future__ import annotations

import json
import re
import sys
from pathlib import Path
from typing import Any

from workspace import WorkspaceError, require_workspace_root, resolve_within


class ProgressError(RuntimeError):
    pass


FUNCTION_PATTERN = re.compile(
    r"^nonmatching\s+(?P<name>\S+),\s+0x(?P<size>[0-9A-Fa-f]+)$"
)


def parse_integer(value: Any, description: str) -> int:
    if isinstance(value, int) and not isinstance(value, bool):
        return value
    if isinstance(value, str):
        try:
            return int(value, 0)
        except ValueError as error:
            raise ProgressError(
                f"{description} is not a valid integer: {value}"
            ) from error
    raise ProgressError(f"{description} must be an integer or integer string")


def load_text_size(root: Path) -> int:
    path = resolve_within(
        root, "config/slus_01411/image_map.json", must_exist=True
    )
    with path.open("r", encoding="utf-8") as handle:
        image_map = json.load(handle)
    for region in image_map["regions"]:
        if region["name"] == "text":
            start = parse_integer(region["file_start"], "text.file_start")
            end = parse_integer(region["file_end"], "text.file_end")
            return end - start
    raise ProgressError("image map has no text region")


def parse_functions(path: Path) -> list[dict[str, Any]]:
    functions: list[dict[str, Any]] = []
    handwritten = False
    with path.open("r", encoding="utf-8") as handle:
        for raw_line in handle:
            line = raw_line.strip()
            if line == "/* Handwritten function */":
                handwritten = True
                continue

            match = FUNCTION_PATTERN.fullmatch(line)
            if match:
                functions.append(
                    {
                        "name": match.group("name"),
                        "size": int(match.group("size"), 16),
                        "handwritten": handwritten,
                    }
                )
                handwritten = False
                continue

            if line and not line.startswith("/*"):
                handwritten = False
    if not functions:
        raise ProgressError(f"{path}: no generated functions found")
    return functions


def atomic_write_json(path: Path, value: dict[str, Any]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    temporary = path.with_name(f"{path.name}.tmp")
    try:
        temporary.write_text(
            json.dumps(value, indent=2, sort_keys=True) + "\n",
            encoding="utf-8",
        )
        temporary.replace(path)
    except OSError:
        temporary.unlink(missing_ok=True)
        raise


def calculate(root: Path) -> dict[str, Any]:
    assembly_path = resolve_within(
        root, "tmp/splat/asm/entry.s", must_exist=True
    )
    functions = parse_functions(assembly_path)
    text_bytes = load_text_size(root)
    function_bytes = sum(function["size"] for function in functions)
    handwritten = [
        function for function in functions if function["handwritten"]
    ]
    handwritten_bytes = sum(function["size"] for function in handwritten)
    if function_bytes > text_bytes:
        raise ProgressError(
            f"function bytes {function_bytes:#x} exceed text size {text_bytes:#x}"
        )

    return {
        "target": "SLUS-01411",
        "text_bytes": text_bytes,
        "function_count": len(functions),
        "function_bytes": function_bytes,
        "handwritten_function_count": len(handwritten),
        "handwritten_function_bytes": handwritten_bytes,
        "assembly_function_bytes": function_bytes - handwritten_bytes,
        "matching_c_function_count": 0,
        "matching_c_bytes": 0,
        "unassigned_text_bytes": text_bytes - function_bytes,
    }


def main() -> int:
    try:
        root = require_workspace_root()
        progress = calculate(root)
        output = resolve_within(root, "tmp/reports/progress.json")
        atomic_write_json(output, progress)
    except (
        ProgressError,
        WorkspaceError,
        OSError,
        UnicodeError,
        KeyError,
        TypeError,
        ValueError,
        json.JSONDecodeError,
    ) as error:
        print(f"error: {error}", file=sys.stderr)
        return 1

    print(f"functions:          {progress['function_count']}")
    print(f"function bytes:     {progress['function_bytes']:#x}")
    print(
        "handwritten:        "
        f"{progress['handwritten_function_count']} functions, "
        f"{progress['handwritten_function_bytes']:#x} bytes"
    )
    print(f"assembly functions: {progress['assembly_function_bytes']:#x} bytes")
    print(f"matching C:         {progress['matching_c_bytes']:#x} bytes")
    print(f"unassigned text:    {progress['unassigned_text_bytes']:#x} bytes")
    print(f"report:             {output.relative_to(root)}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
