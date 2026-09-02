# Grouped Translation Units

## Contract

`config/slus_01411/matching_c.json` continues to record one row per matched
function, but multiple rows may now share one C source when all of these
conditions hold:

1. The functions are contiguous in executable address order.
2. Every member uses the same compiler profile.
3. The source defines every member in that same order.
4. The sum of the member sizes exactly covers the C subsegment.
5. A clean full build remains byte-identical to `game/SLUS_014.11`.

`tools/project/generate_build_config.py` enforces the first four conditions and
emits one `text_sources.json` object with a `members` list. The full executable
match enforces the fifth.

Single-function refinement integration refuses to replace one member of a
grouped source. Semantic renaming may update symbols inside a grouped source,
but it does not automatically rename a source file owned by multiple
functions.

Historical external-candidate hashes remain provenance for the source tested
at integration time. The repository audit checks that the current pure-C
translation unit defines the expected symbol with the accepted profile; the
full executable hash remains the authority after later semantic renames or
source grouping.

## Initial groups

| Translation unit | Profile | Members |
|---|---|---|
| `src/game/duel_card_checks.c` | `gcc_2_8_1_g0_split` | `Duel_CheckEquip` (`0x80019A08`), `Duel_CheckFusion` (`0x80019A60`) |
| `src/game/duel_battle_stats.c` | `gcc_2_8_1_g8` | `Duel_CalcBattleAttack` (`0x8001EF1C`), `Duel_CalcBattleDefense` (`0x8001EF78`) |
| `src/game/ai_fusion.c` | `gcc_2_8_1_g0_split` | `AiScript_FindEquipTarget` (`0x8007249C`) through `Ai_CompleteFusion` (`0x800727C0`) |
| `src/game/ai_script_vm.c` | `gcc_2_8_1_g0_split` | `AiScript_Init` (`0x800705D8`), `AiScript_Run` (`0x80070650`) |
| `src/game/ai_set_queries.c` | `gcc_2_8_1_g0_split` | `Ai_IsCardInSet` (`0x80070870`), `Ai_IsTypeInSet` (`0x800708C4`) |
| `src/game/ai_script_card_info.c` | `gcc_2_8_1_g0_split` | `AiScript_TestHighStat` (`0x80071194`) through `AiScript_LoadCardID` (`0x800712B4`) |
| `src/game/ai_script_jumps.c` | `gcc_2_8_1_g0_split` | `AiScript_JumpBetween` (`0x80070BB8`), `AiScript_JumpRandom` (`0x80070C60`) |
| `src/game/ai_script_end.c` | `gcc_2_8_1_g0` | `AiScript_EndHand` (`0x80070FF8`), `AiScript_EndField` (`0x80071000`) |
| `src/game/ai_script_skip.c` | `gcc_2_8_1_g0` | `AiScript_SkipHand` (`0x80072F1C`), `AiScript_SkipField` (`0x80072F54`) |
| `src/game/ai_script_nop.c` | `gcc_2_8_1_g0` | `AiScript_HandNop` (`0x80073300`), `AiScript_FieldNop` (`0x80073308`) |
| `src/game/ai_script_combo.c` | `gcc_2_8_1_g0_split` | `AiScript_TestPinned` (`0x8007154C`), `AiScript_StartCombo` (`0x800715C4`) |
| `src/game/ai_script_actions.c` | `gcc_2_8_1_g0_split` | `AiScript_PlayFaceUp` (`0x80072F8C`), `AiScript_SetPosition` (`0x80073050`) |
| `src/game/ai_script_state_ops.c` | `gcc_2_8_1_g0_split` | Four state-flag handlers at `0x80073448`-`0x80073474`, then `AiScript_MoveCard` (`0x80073480`) |
| `src/game/file_stream.c` | `gcc_2_8_1_g8` | File-state initialization (`0x80013898`), `File_GetPosition`, and three transfer setup helpers through `0x80013A94` |
| `src/game/file_cd_callbacks.c` | `gcc_2_8_1_g8_split` | Three asynchronous disc callbacks at `0x800140A0-0x800141A8` |
| `src/game/file_read_callbacks.c` | `gcc_2_8_1_g8_split` | Three file/read completion callbacks at `0x80014294-0x80014390` |
| `src/game/build_deck_compare.c` | `gcc_2_8_1_g0_split` | `BuildDeck_CompareCard` (`0x80032B60`) and its reverse-primary comparator at `0x80032BD4` |
| `src/game/duel_rewards.c` | `gcc_2_8_1_g8_split` | `Duel_SelectCardDrop` (`0x80021810`), `Duel_AwardCard` (`0x80021894`) |
| `src/game/main_debug.c` | `gcc_2_8_1_g8` | Debug-mode setup wrapper (`0x8002CDE8`), `Main_RunDebugMenu` (`0x8002CE08`) |
| `src/game/sound_output.c` | `gcc_2_8_1_g8` | Sound output initialization/control helpers from `0x80046F58` through `0x80047278`, including `SD_SetOutputType` |
| `src/game/sound_frontend.c` | `gcc_2_8_1_g8` | Eight game-facing sound command wrappers from `SD_SEPlayFull` (`0x8003FEE0`) through `0x8003FFFC` |
| `src/game/sound_init.c` | `gcc_2_8_1_g0` | Thirteen music/sequence and secondary sound-state initialization helpers from `0x80049200` through `0x800495EC`, including `SD_Init` |
| `src/game/sound_voice_selection.c` | `gcc_2_8_1_g0` | Five voice lifetime, selection, and activation helpers from `0x800478EC` through `0x80047BB4` |
| `src/game/sound_voice_slots.c` | `gcc_2_8_1_g0` | Voice release polling (`0x80047C70`) and four-slot search/removal (`0x80047CC4`) |
| `src/game/sound_voice_status.c` | `gcc_2_8_1_g0` | Late voice cleanup (`0x80047EC4`) and voice-group mask selection (`0x80047F38`) |
| `src/game/sound_sequence_state.c` | `gcc_2_8_1_g0` | Two sequence-state setters (`0x800490F0`, `0x80049108`) and the active-state test at `0x80049120` |
| `src/game/sound_term.c` | `gcc_2_8_1_g0` | Pre-termination cleanup (`0x80049640`) and `SD_Term` (`0x80049694`) |
| `src/game/sound_buffer_init.c` | `gcc_2_8_1_g0` | Sound work-buffer pointer setup (`0x80044D48`) and channel-volume defaults (`0x80044DA0`) |
| `src/game/sound_mix.c` | `gcc_2_8_1_g0` | CD mix packet setup (`0x80044F58`) and current-volume query (`0x80044FE4`) |
| `src/game/sound_command_queue.c` | `gcc_2_8_1_g0` | Command marker insertion (`0x80045114`) and command wrapper (`0x800451E0`) |
| `src/game/sound_state_control.c` | `gcc_2_8_1_g8` | Secondary-state activation (`0x8004695C`) and main sound-state flag setup (`0x80046990`) |
| `src/game/sound_command_wrappers.c` | `gcc_2_8_1_g8` | Four command/sequence wrappers at `0x800473CC-0x80047458` |
| `src/game/sound_voice_data.c` | `gcc_2_8_1_g0` | Voice-step assignment (`0x80048C0C`) and a 512-word transfer helper (`0x80048C70`) |
| `src/game/sound_secondary_reset.c` | `gcc_2_8_1_g0` | Low-level state query (`0x800498BC`) and secondary-state reset (`0x800498F8`) |
| `src/game/sound_secondary_playback.c` | `gcc_2_8_1_g0` | Three secondary playback lifecycle helpers at `0x80049BAC-0x80049CB0` |
| `src/game/sound_secondary_params.c` | `gcc_2_8_1_g0` | Secondary playback parameter setters/status query at `0x80049EC8-0x80049F50` |

These pilots reduce four one-function source files to two coherent
translation units and reduce generated C objects from 769 to 767. Function
emission order and the complete retail executable SHA-256 remain unchanged.

After the subsystem pass, all 769 matching functions build from 733
translation units. Eighteen grouped units contain 54 functions; the largest is
the ten-function `sound_output.c` block.

## Expansion policy

Expand grouping only after names and behavior are stable. Prefer small
subsystem runs with shared declarations. Do not bridge an assembly function,
mix compiler profiles, reorder functions, or merge a function whose remaining
inline assembly would make later refinement unsafe.
