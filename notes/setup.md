# Project Setup

## Required local inputs

Place the North American game files at the exact paths listed in
`config/slus_01411/files.sha256`. The primary target is:

```text
game/SLUS_014.11
```

The game files remain ignored and untracked. Validate them before any analysis:

```sh
make verify-inputs
```

The expected executable SHA-256 is:

```text
84a54ed74f3d0edd6d81380839f7e4ef5bfb21ecea18be9a062bd6bfa5a45c88
```

## Workspace rule

Run all commands from the repository root. Project scripts reject execution
from another directory and reject absolute or escaping project paths.

All project-managed software is installed beneath `tools/`. All generated
output, caches, compiler scratch files, and reports are written beneath `tmp/`.
All durable documentation is kept beneath `notes/`.

## Bootstrap

```sh
make tools
make check-tools
```

The bootstrap is pinned by:

- `tools/bootstrap/tools.json`
- `tools/bootstrap/requirements.lock`
- `tools/bootstrap/bootstrap-requirements.lock`
- `tools/bootstrap/binutils.json`
- `tools/bootstrap/old_gcc.json`

The installed state is ignored by Git. The bootstrap does not install global or
user-level packages.

## First verified build

```sh
make map
make match
make classify-functions
make progress
```

`make match` succeeds only when the complete rebuilt PS-X EXE is byte-identical
to the supplied target.

## Optional PsyQ compiler candidates

No proprietary compiler is downloaded by this project. A lawfully obtained
candidate may be placed beneath an ignored directory in `tools/toolchains/`.
Record its exact hash and provenance in `notes/toolchain.md` before using it.

The current evidence requires testing late ASPSX behavior and likely CCPSX
`-O2`/`-G8` output. The user independently verified Psy-Q 4.6.1 with multiple
tools, so 4.6.1 is the selected SDK version. Its `LIBDS.LIB` was also
distributed with Psy-Q 4.7, so that library alone cannot distinguish the two
packages. Exact compiler and library binaries must still be recorded by hash
when added to the workspace.

The bootstrapped GCC 2.8.1 PSX compiler is a reproducible diagnostic stand-in,
not Sony CCPSX. The build always supplies explicit PSX target flags as recorded
in `notes/toolchain.md`.
