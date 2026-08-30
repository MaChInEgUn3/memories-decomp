# SLUS-01411 Memory Map

## Executable container

| Property | Value |
|---|---|
| File size | `0x1D0800` |
| Header | `0x000000-0x000800` |
| Load address | `0x80010000` |
| Loaded image end | `0x801E0000` |
| Entry point | `0x800129D8` |
| Entry file offset | `0x31D8` |
| Runtime global pointer | `0x8009AF08` |
| Header stack base | `0x801FFFF0` |

The PS-X EXE header declares the complete `0x1D0000`-byte loaded payload as its
text image. The finer regions below are recovered from executable structure and
startup behavior rather than from populated header data/BSS fields.

## Top-level regions

| Region | File range | VRAM range | Size | Classification |
|---|---:|---:|---:|---|
| Header | `0x000000-0x000800` | Not loaded | `0x800` | PS-X EXE header |
| Initial data | `0x000800-0x0031D8` | `0x80010000-0x800129D8` | `0x29D8` | Pointers, strings, constants, jump tables |
| Resident text | `0x0031D8-0x080ED4` | `0x800129D8-0x800906D4` | `0x7DCFC` | MIPS code with small embedded non-function ranges |
| Text padding | `0x080ED4-0x080EE0` | `0x800906D4-0x800906E0` | `0xC` | Zero alignment |
| Initialized data | `0x080EE0-0x08B890` | `0x800906E0-0x8009B090` | `0xA9B0` | Runtime metadata, paths, tables, globals |
| BSS image | `0x08B890-0x0EEF28` | `0x8009B090-0x800FE728` | `0x63698` | Zero bytes explicitly cleared by startup |
| Reserved zero | `0x0EEF28-0x12A800` | `0x800FE728-0x8013A000` | `0x3B8D8` | Zero gap before load slots |
| Overlay slots | `0x12A800-0x19C800` | `0x8013A000-0x801AC000` | `0x72000` | Almost-empty fixed-address runtime load banks |
| Tail data | `0x19C800-0x1D0800` | `0x801AC000-0x801E0000` | `0x34000` | Structured resident tables and encoded data |

`config/slus_01411/image_map.json` records a SHA-256 for every row, and
`make map` verifies continuity, VRAM translation, fill bytes, hashes, the final
resident return instruction, and startup BSS-clear operands.

## Resident text boundaries

The entry point is the first resident instruction. Bytes immediately before it
are strings and pointer tables.

The final resident function returns at `0x800906CC`, with its delay-slot `nop`
at `0x800906D0`. Twelve zero bytes follow before initialized data starts at
`0x800906E0`.

## BSS evidence

The first four entry-point instructions form two `lui`/`addiu` pairs:

- Clear start: `0x8009B090`
- Clear end: `0x800FE728`

The second address requires signed-immediate arithmetic:
`0x80100000 + (int16_t)0xE728 = 0x800FE728`.

The corresponding executable bytes are all zero. An additional zero region
continues to `0x8013A000`, but startup does not include that gap in this clear
loop, so it is classified separately.

## Runtime load slots

The region beginning at `0x8013A000` contains fixed slot boundaries also
referenced near the start of the executable, including:

- `0x8013A000`
- `0x8013B000`
- `0x80146000`
- `0x80168000`
- `0x8017A000`
- `0x8017B000`
- `0x80180000`

Each begins with a small identifier and is otherwise initially almost entirely
zero. Resident code contains unresolved calls into several of these ranges.
They are therefore treated as runtime-loaded overlay or module destinations,
not resident executable functions. Recovering their source archives is outside
the current executable-only matching scope.
