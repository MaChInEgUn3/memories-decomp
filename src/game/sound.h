#ifndef YUGIOH_GAME_SOUND_H
#define YUGIOH_GAME_SOUND_H

#include "../types.h"

typedef struct {
    u8 command;
    u8 data[0x2F];
} SDCommand;

typedef struct {
    u8 pad00[4];
    u32 field_0004;
} SDValueLink;

typedef struct {
    u16 field_0000;
    u8 pad0002[2];
    u16 field_0004;
    u8 pad0006[0x36];
    u32 field_003C;
    u16 flags_0040;
    u16 mix_scale;
    u8 pad0044[4];
    u8 output_type;
    u8 field_0049;
    u8 flags_004A;
    u8 pad004B;
    s16 command_count;
    u8 pad004E[0x32];
    SDCommand commands[16];
    u8 pad0380[0x44];
    s32 field_03C4;
    s32 field_03C8;
    u16 field_03CC;
    u16 field_03CE;
    u8 pad03D0[0x34];
    u16 voice_ids[4];
    u8 pad040C[4];
    u8 field_0410;
    u8 pad0411[0x13];
    u8 voice_value[4];
    u8 voice_step[4];
    u16 voice_timer[4];
    u8 voice_active_mask;
    u8 field_0435;
    u8 pad0436[2];
    u32 field_0438;
    u16 *field_043C;
    u16 field_0440;
    u16 field_0442;
    u8 pad0444[4];
    SDValueLink *field_0448;
    u8 pad044C[0xC4];
    s16 cd_volume;
    s16 field_0512;
    u8 channel_volume[2];
    u8 pad0516[0x1D];
    u8 mix_multiplier;
    u8 pad0534[0x1030];
    u16 *music_track;
    u8 pad1568[0x10];
    s16 field_1578;
    s16 field_157A;
    u8 pad157C[2];
    s16 field_157E;
    u8 pad1580[2];
    s16 field_1582;
    u8 field_1584;
    u8 pad1585;
    s16 field_1586;
    s16 field_1588;
    u8 pad158A[0x63];
    u8 field_15ED;
    u8 field_15EE;
    u8 field_15EF;
    u8 pad15F0[0x28];
    u8 busy;
    u8 pad1619[0x32];
    u8 field_164B;
} SDValue;

typedef char SDCommand_size_must_be_0x30[
    sizeof(SDCommand) == 0x30 ? 1 : -1
];
typedef char SDValueLink_size_must_be_0x08[
    sizeof(SDValueLink) == 0x08 ? 1 : -1
];
typedef char SDValue_size_must_be_0x164C[
    sizeof(SDValue) == 0x164C ? 1 : -1
];

extern SDValue *g_SDValue;

#endif
