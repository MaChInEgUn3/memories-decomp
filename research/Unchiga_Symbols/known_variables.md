# Known variable / data names (SLUS_014.11)

GENERATED from config/symbol_addrs.txt -- regenerate with tools/gen_research_notes.py
after any naming change. Source tags: `idb2018` = idb_raymond_2018 import, `ramMap` =
datacrystal RAM map, `dotr` = DotR-style naming, `psyq` = original SDK symbol
(libsyms signature match), `fleet` = behavior-derived by this project. Evidence: NAMING.md.

63 named variables (61 game-meaningful, 0 sdk, 2 mechanical).

## Game-meaningful names

Names that say what something IS in the game.

| address | name | source |
|---|---|---|
| 0x8009078C | `fileNames` | idb2018 |
| 0x800909D4 | `terrainBoosts` | idb2018 |
| 0x800916E0 | `aiFunctionTable` | idb2018 |
| 0x800917F0 | `oppData` | idb2018 |
| 0x8009B1D5 | `playingSide` | idb2018 |
| 0x8009B258 | `g_GridCursorCol` | live |
| 0x8009B259 | `g_GridCursorRow` | live |
| 0x8009B2C4 | `g_DebugSoundId` | ramMap |
| 0x8009B338 | `selectedCardId` | idb2018 |
| 0x8009B361 | `opponentId` | idb2018 |
| 0x8009B364 | `terrain` | idb2018 |
| 0x8009B366 | `g_OpponentGridCol` | live |
| 0x8009B367 | `g_OpponentGridRow` | live |
| 0x8009B408 | `g_SoundMode_s` | live |
| 0x800E9EA8 | `filePositions` | idb2018 |
| 0x800EA002 | `playerDisplayedLp` | ramMap |
| 0x800EA004 | `playerLp` | ramMap |
| 0x800EA022 | `cpuDisplayedLp` | idb2018 |
| 0x800EA024 | `cpuLp` | idb2018 |
| 0x800EA118 | `g_FusionResult` | ramMap |
| 0x800F5B98 | `aiMemory` | idb2018 |
| 0x800F5BE8 | `aiStruct` | idb2018 |
| 0x800F5BEC | `aiWord1` | idb2018 |
| 0x800F5BF0 | `aiWord2` | idb2018 |
| 0x800F5BFC | `aiByte2` | idb2018 |
| 0x800F5C00 | `aiWordArray2` | idb2018 |
| 0x800FE6F8 | `prngSeed` | idb2018 |
| 0x8016D410 | `g_PasswordDigits` | live |
| 0x80177F94 | `playerPerm` | idb2018 |
| 0x80177FBC | `cpuPerm` | idb2018 |
| 0x80177FE8 | `playerDeckTmp` | idb2018 |
| 0x80178038 | `cpuDeckTmp` | idb2018 |
| 0x801781D8 | `cpuDeckPool` | idb2018 |
| 0x8017878C | `powDropPool` | idb2018 |
| 0x80178D40 | `bcdDropPool` | idb2018 |
| 0x801792F4 | `tecDropPool` | idb2018 |
| 0x801798A8 | `rankScoreDiffs` | idb2018 |
| 0x801799D8 | `ritualData` | idb2018 |
| 0x80179A04 | `rankScore` | idb2018 |
| 0x80179A14 | `g_CardDropId` | ramMap |
| 0x8017A1D8 | `equipTable` | idb2018 |
| 0x8017C2D8 | `fusionTable` | idb2018 |
| 0x80184594 | `g_MenuCursor` | live |
| 0x801A7B64 | `playerMonsters` | idb2018 |
| 0x801A7B80 | `playerMonster2` | idb2018 |
| 0x801A7B9C | `playerMonster3` | idb2018 |
| 0x801A7BB8 | `playerMonster4` | idb2018 |
| 0x801A7BD4 | `playerMonster5` | idb2018 |
| 0x801A7E20 | `g_PlayerHand` | ramMap |
| 0x801A8000 | `handAiScript` | idb2018 |
| 0x801A8008 | `g_CardPasswords` | ramMap |
| 0x801AB000 | `activeCards` | idb2018 |
| 0x801D0200 | `playerDeck` | idb2018 |
| 0x801D0250 | `trunk` | idb2018 |
| 0x801D06F4 | `g_FreeDuelUnlocks` | ramMap |
| 0x801D07BC | `g_LastCardDrops` | ramMap |
| 0x801D07E0 | `starchips` | idb2018 |
| 0x801D4244 | `statsArray` | idb2018 |
| 0x801D4D8E | `nameKeys` | idb2018 |
| 0x801D56A8 | `g_CardDropId2` | ramMap |
| 0x801EA800 | `musicTrack` | idb2018 |

## Mechanical names

Fleet-written descriptions of verified *mechanics*, not game meaning (e.g. `flag80_test_and_set` tests-and-sets bit 0x80 of something). Accurate but low readability; each is a candidate for a meaningful upgrade when evidence appears.

| address | name | source |
|---|---|---|
| 0x80090E0C | `pow10_table` | fleet |
| 0x8009B408 | `g_SoundMode` | fleet |

