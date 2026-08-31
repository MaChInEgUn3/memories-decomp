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
| Game/engine functions | 1,194 |
| Game/engine function bytes | 396,212 (`0x60BB4`) |
| PsyQ CRT/SDK functions | 598 |
| PsyQ CRT/SDK function bytes | 117,332 (`0x1CA54`) |
| Game functions heuristically marked handwritten | 63 |
| Game handwritten-function bytes | 46,236 (`0xB49C`) |
| Remaining game assembly functions | 625 |
| Remaining game assembly-function bytes | 317,816 (`0x4D978`) |
| Embedded/unassigned text bytes | 1,780 (`0x6F4`) |
| Matching C functions | 506 |
| Matching C bytes | 32,160 (`0x7DA0`) |

SDK classification is based on verified ownership boundaries. Handwritten
classifications inside the game region remain provisional Splat/spimdisasm
findings.

## Generate metrics

```sh
make progress
```

The command regenerates the split, prints the current metrics, and writes
machine-readable output to `tmp/reports/progress.json`.

Only matching C contributes to C progress. Exact generated assembly and
classified binary data are necessary for a matching baseline but do not count
as decompiled C.

The first matching function was `func_800736C4`, which prints the
`check_point` diagnostic and its numbered separator. The matching set now
spans the full resident game address range and includes bytecode readers,
checkpoint helpers, wrappers, getters/setters, field updates, little-endian
decoders, address-return helpers, transfer helpers, and control-flow routines.

All 506 matching functions currently use the GCC 2.8.1 PSX probe:

| Compiler profile | Functions |
|---|---:|
| `gcc_2_8_1_g8` | 286 |
| `gcc_2_8_1_g8_split` | 46 |
| `gcc_2_8_1_g0` | 149 |
| `gcc_2_8_1_g0_split` | 25 |

The attempt ledger currently records 1,489 outcomes: 506 matches, 895
nonmatches, and 88 deferred functions whose six-attempt search budgets are
exhausted. Deferred functions remain exact assembly and are not retried without
genuinely new evidence.
