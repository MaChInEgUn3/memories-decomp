# Decompilation Progress

## Current baseline

The project has a deterministic, byte-identical assembly/data baseline:

```text
Target:  game/SLUS_014.11
Output:  tmp/project-build/SLUS_014.11
SHA-256: 84a54ed74f3d0edd6d81380839f7e4ef5bfb21ecea18be9a062bd6bfa5a45c88
```

## Resident text metrics

| Metric | Value |
|---|---:|
| Resident text bytes | 515,324 (`0x7DCFC`) |
| Discovered functions | 1,792 |
| Bytes assigned to functions | 513,544 (`0x7D608`) |
| Functions heuristically marked handwritten | 116 |
| Handwritten-function bytes | 54,024 (`0xD308`) |
| Remaining assembly-function bytes | 459,520 (`0x70300`) |
| Embedded/unassigned text bytes | 1,780 (`0x6F4`) |
| Matching C bytes | 0 |

Handwritten classifications are provisional Splat/spimdisasm findings and do
not yet distinguish game assembly from PsyQ or other library implementations.

## Generate metrics

```sh
make progress
```

The command regenerates the split, prints the current metrics, and writes
machine-readable output to `tmp/reports/progress.json`.

Only matching C contributes to C progress. Exact generated assembly and
classified binary data are necessary for a matching baseline but do not count
as decompiled C.
