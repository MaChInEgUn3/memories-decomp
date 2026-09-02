# Sound Driver State

`g_SDValue` is a global pointer to the main sound-driver work area. Its name is
present in the retail debug strings and is also used by the successor game's
sound subsystem. Local matching code confirms that the global itself stores a
pointer rather than an inline structure.

`src/game/sound.h` defines the currently verified `SDValue` layout through
offset `0x164B`. Unknown regions remain explicitly padded, and uncertain fields
retain offset-based names. The header does not claim that this is the original
Konami type or field naming.

## Confirmed fields

| Offset | Field | Evidence |
|---|---|---|
| `0x0040` | `flags_0040` | Multiple control and cleanup routines set/test driver status bits. |
| `0x0042` | `mix_scale` | CD mix calculation uses it as a 16-bit scale. |
| `0x0048` | `output_type` | `SD_SetOutputType`; live stereo/mono traces establish values 0 and 1. |
| `0x004A` | `flags_004A` | Initialization and command processing use independent bits. |
| `0x004C` | `command_count` | Bounds the 16-entry command scan. |
| `0x0080` | `commands[16]` | 16 records, each `0x30` bytes; command at `+0x00` and eight verified 32-bit argument/result slots at `+0x10`-`+0x2C`. |
| `0x0404` | `voice_ids[4]` | Four 16-bit voice identifiers. |
| `0x0424` | `voice_value[4]` | Four per-voice byte values reduced by `voice_step`. |
| `0x0428` | `voice_step[4]` | Four per-voice decrement values. |
| `0x042C` | `voice_timer[4]` | Four 16-bit countdown timers. |
| `0x0434` | `voice_active_mask` | One bit per voice entry. |
| `0x0510` | `cd_volume` | Sound output changes recalculate and store this signed 16-bit value. |
| `0x0514` | `channel_volume[2]` | Two byte channel-volume scalars. |
| `0x0533` | `mix_multiplier` | Multiplies the shared CD mix scale. |
| `0x1564` | `music_track` | Pointer defaults to `0x801EA800`; its first 16-bit value is initialized to `0xFFFF`. |
| `0x1618` | `busy` | Command registration tests and sets this byte. |

The remaining named `field_XXXX` members have verified offsets and widths but
insufficient semantic evidence for stronger names.

## Structure safeguards

The header contains compile-time size assertions for:

- `SDCommand`: `0x30`;
- `SDValueLink`: `0x08`;
- `SDValue`: `0x164C`.

Some translation units may continue using raw pointer views when required to
preserve GCC relocation shape. The shared header remains the layout reference,
while exact executable matching decides whether a typed field access is safe
for a particular function.

The contiguous output/control block at `0x80046F58-0x80047278` now builds as
`src/game/sound_output.c`. Its ten functions use `SDValue` and `SDCommand`
directly, including output-type reads/writes, driver flags, CD-volume reuse,
and construction of three command variants.
