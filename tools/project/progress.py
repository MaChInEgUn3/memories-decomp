#!/usr/bin/env python3

from __future__ import annotations

import json
import sys
from pathlib import Path
from typing import Any

from function_inventory import (
    Function,
    InventoryError,
    load_inventory,
    parse_generated_function_tree,
)
from workspace import WorkspaceError, require_workspace_root, resolve_within


class ProgressError(RuntimeError):
    pass


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


def validate_inventory(
    generated: list[Function], inventory: list[Function]
) -> None:
    generated_by_address = {function.address: function for function in generated}
    inventory_by_address = {function.address: function for function in inventory}
    if len(generated_by_address) != len(generated):
        raise ProgressError("generated function list contains duplicate addresses")
    if len(inventory_by_address) != len(inventory):
        raise ProgressError("function inventory contains duplicate addresses")
    if set(generated_by_address) != set(inventory_by_address):
        raise ProgressError(
            "function inventory does not match the generated split; run make inventory"
        )
    for address, generated_function in generated_by_address.items():
        inventory_function = inventory_by_address[address]
        if (
            generated_function.size != inventory_function.size
            or generated_function.name != inventory_function.name
        ):
            raise ProgressError(
                f"function inventory differs at {address:#010x}; "
                "run make inventory"
            )


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
    assembly_root = resolve_within(
        root, "tmp/splat/asm", must_exist=True
    )
    generated = parse_generated_function_tree(assembly_root)
    inventory_path = resolve_within(
        root, "config/slus_01411/functions.csv", must_exist=True
    )
    functions = load_inventory(inventory_path)
    validate_inventory(generated, functions)
    text_bytes = load_text_size(root)
    function_bytes = sum(function.size for function in functions)
    handwritten = [
        function for function in functions if function.status == "handwritten_asm"
    ]
    handwritten_bytes = sum(function.size for function in handwritten)
    assembly = [
        function for function in functions if function.status == "unmatched_asm"
    ]
    assembly_bytes = sum(function.size for function in assembly)
    sdk = [function for function in functions if function.status == "sdk_asm"]
    sdk_bytes = sum(function.size for function in sdk)
    matching = [function for function in functions if function.status == "matching_c"]
    matching_bytes = sum(function.size for function in matching)
    modules: dict[str, dict[str, int]] = {}
    for function in functions:
        module = modules.setdefault(
            function.module,
            {"function_count": 0, "function_bytes": 0},
        )
        module["function_count"] += 1
        module["function_bytes"] += function.size
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
        "assembly_function_count": len(assembly),
        "assembly_function_bytes": assembly_bytes,
        "sdk_function_count": len(sdk),
        "sdk_function_bytes": sdk_bytes,
        "matching_c_function_count": len(matching),
        "matching_c_bytes": matching_bytes,
        "modules": modules,
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
        InventoryError,
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
    print(
        "SDK/startup:        "
        f"{progress['sdk_function_count']} functions, "
        f"{progress['sdk_function_bytes']:#x} bytes"
    )
    print(f"assembly functions: {progress['assembly_function_bytes']:#x} bytes")
    print(f"matching C:         {progress['matching_c_bytes']:#x} bytes")
    print(f"unassigned text:    {progress['unassigned_text_bytes']:#x} bytes")
    print(f"report:             {output.relative_to(root)}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
