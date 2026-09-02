#include "../types.h"
#include "sound.h"

typedef struct {
    u8 type;
    u8 pad01;
    s16 value;
    s32 pad04;
    s32 data;
    u8 pad0C[0x24];
} SDSequenceCommand;

extern u8 *D_8009B458;

extern void func_80045BE8(SDSequenceCommand *);
extern void func_80046294(void);
extern void func_800471D0(s32, s32, s32, s32, s32, s32);
extern void func_80049010(void);
extern void func_80049138(s16, s32);
extern s32 func_800496C4(void *, s32, s32);
extern void func_8004A6D8(void);
extern void func_8004B854(void);
extern void func_8004B9E0(void);
extern void func_80074E60(void);
extern void func_80077FF0(s32);

void func_80049200(s32 value)
{
    func_80049230((s16)value, g_SDValue->field_164B);
}

void func_80049230(s32 value, s32 data)
{
    SDSequenceCommand command;
    s16 small = value;

    if (small < 0) {
        func_80049010();
        return;
    }
    if (*g_SDValue->music_track != (small >> 4))
        func_80049138(small, 1);
    command.type = 0x48;
    command.value = value;
    command.data = (s16)data;
    func_80045BE8(&command);
    g_SDValue->field_1582 = data;
    g_SDValue->field_1584 = 255;
}

void SD_Init(void)
{
    func_80046294();
    func_80049010();
    func_80077FF0(0);
}

void func_80049308(void)
{
    SDValue *state = g_SDValue;

    if (state->field_157A != 0) {
        u8 *entry = (u8 *)state->music_track;
        s32 result = func_800496C4(entry + 0x50, 0, *(s32 *)(entry + 0x0C));

        g_SDValue->field_157A = result;
        if ((result << 16) != 0) {
            g_SDValue->field_1578 = -1;
            g_SDValue->field_157A = -1;
            return;
        }
    }
    {
        register SDValue *final = g_SDValue;
        register u16 *entry = final->music_track;
        final->field_1578 = *entry;
    }
}

void func_80049394(void *entry)
{
    func_80049010();
    if (entry != 0)
        g_SDValue->music_track = entry;
    else
        g_SDValue->music_track = (u16 *)0x801EA800;
    *g_SDValue->music_track = 0xFFFF;
}

void func_800493F8(void)
{
    u16 *entry;

    func_80049010();
    entry = (u16 *)0x801EA800;
    *(u16 **)((u8 *)g_SDValue + 0x1564) = entry;
    entry[0] = 0xFFFF;
}

void func_80049434(void)
{
    u8 *state;
    u8 *other;
    u8 *third;
    u8 *fourth;
    u8 *fifth;
    u8 *final;

    D_8009B458[0x500] = 0;
    D_8009B458[0x501] = 0;
    D_8009B458[0x502] = 0;
    state = D_8009B458;
    *(s16 *)(state + 0x510) = 20;
    state[0x814] = 0;
    other = D_8009B458;
    *(s16 *)(state + 0x512) = 127;
    *(s16 *)(state + 0x514) = 127;
    *(s16 *)(state + 0x516) = 127;
    other[0x815] = 0;
    third = D_8009B458;
    third[0x4BD] = 127;
    fourth = D_8009B458;
    *(s16 *)(third + 0x4A4) = -1;
    fourth[0x4BE] = 127;
    fifth = D_8009B458;
    fifth[0x4BF] = 64;
    final = D_8009B458;
    *(s16 *)(final + 0x7E0) = -1;
    *(s16 *)(final + 0x7E2) = 0;
    *(s16 *)(final + 0x7E6) = 127;
    *(s16 *)(final + 0x7E4) = 127;
    *(s32 *)(final + 0x80C) = 0;
    *(s32 *)(final + 0x810) = 0;
    *(s32 *)(final + 0x81C) = 0x1000;
}

void func_800494F4(s32 *data)
{
    u32 i = 0;

    D_8009B458 = (u8 *)data;
    do {
        *data = 0;
        i++;
        data++;
    } while (i < 530);
    func_80074E60();
    func_8004A6D8();
    func_80049434();
}

void func_80049544(void)
{
    s32 value = *(s32 *)(D_8009B458 + 0x81C);

    if (value > 0) {
        if (value < 4)
            func_8004B854();
    }
    D_8009B458[0x814] = 1;
}

void func_80049594(s32 value)
{
    *(s32 *)(D_8009B458 + 0x81C) = value;
}

void func_800495A4(void)
{
    if (D_8009B458[0x814])
        func_8004B9E0();
}

void func_800495DC(void)
{
    D_8009B458[0x815] = 0;
}

void func_800495EC(void)
{
    D_8009B458[0x815] = 1;
}
