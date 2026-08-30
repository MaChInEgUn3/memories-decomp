# Build and Match Workflow

## Workspace contract

Run every command from the repository root. Project entry points validate the
current directory and reject paths that resolve outside the workspace.

Project-managed dependencies are installed beneath `tools/`. Generated files,
package caches, compiler scratch files, split output, linker maps, and rebuilt
executables stay beneath `tmp/`.

## Inputs

Supply the North American `SLUS-01411` files beneath `game/`. They are ignored
by Git and validated against `config/slus_01411/files.sha256`.

```sh
make verify-inputs
```

The executable must have SHA-256:

```text
84a54ed74f3d0edd6d81380839f7e4ef5bfb21ecea18be9a062bd6bfa5a45c88
```

## Local tools

```sh
make tools
make check-tools
```

The bootstrap installs:

- A copied Python 3.10 environment with hash-locked Python packages.
- Splat, spimdisasm, Rabbitizer, and `m2c`.
- Pinned checkouts of asm-differ, maspsx, and decomp-permuter.
- GNU binutils 2.42 configured for `mipsel-none-elf`.

Downloaded archives, installed packages, source checkouts, and toolchains remain
under `tools/`. Temporary build directories remain under `tmp/`.

## Analysis pipeline

```sh
make info
make extract
make map
make split
make inventory
make classify-functions
make progress
```

- `info` prints the verified PS-X EXE header.
- `extract` writes the header, loaded payload, and parsed metadata to
  `tmp/extract/slus_01411/`.
- `map` validates every top-level byte range and its SHA-256.
- `split` deletes only the previous `tmp/splat/` output and regenerates
  disassembly, data assembly, binary regions, linker diagnostics, and automatic
  symbols there.
- `inventory` reconciles generated function boundaries with the tracked
  `config/slus_01411/functions.csv`.
- `classify-functions` applies the verified game/CRT/SDK ownership ranges
  without overwriting a future `matching_c` status.
- `progress` writes current status and ownership metrics to
  `tmp/reports/progress.json`.

The Splat linker script under `tmp/splat/` is diagnostic. The exact build uses
the project linker script at `linker/slus_01411.ld`, which preserves the
original data/text/data ordering and file load addresses.

## Exact baseline build

```sh
make build
make match
```

The build performs these steps:

1. Regenerate the validated Splat split beneath `tmp/splat/`.
2. Assemble the PS-X header, initial data, resident MIPS text, and initialized
   data using the local GNU assembler.
3. Convert each classified binary region into a MIPS object.
4. Link sections with their original VRAM and file load addresses.
5. Emit `tmp/project-build/SLUS_014.11`.
6. Compare its complete size and SHA-256 with the supplied executable.

A successful run prints:

```text
MATCH  tmp/project-build/SLUS_014.11
sha256 84a54ed74f3d0edd6d81380839f7e4ef5bfb21ecea18be9a062bd6bfa5a45c88
```

This baseline does not include the original executable as one opaque blob.
Resident code is regenerated as MIPS assembly, known data ranges are
regenerated as assembly, and remaining binary ranges are separately classified
and excluded from C-decompilation progress.

## Full repository audit

```sh
make audit
```

The audit performs a clean exact build, reconciles the function inventory,
reapplies ownership classifications, generates progress metrics, and checks:

- Every commit author and committer is Copilot.
- No commit contains a `Co-authored-by` trailer.
- No supplied game file, generated output, downloaded dependency, installed
  environment, vendor checkout, or local toolchain is tracked.
- Tracked Markdown documentation is under `notes/`.
- The worktree is clean after deterministic regeneration.

## Cleanup

```sh
make clean
```

Cleanup removes only these known generated paths when present:

- `tmp/extract/`
- `tmp/splat/`
- `tmp/project-build/`
- `tmp/reports/`

It does not remove downloaded tools, toolchains, user-supplied game files, or
the separate binutils bootstrap build directory.
