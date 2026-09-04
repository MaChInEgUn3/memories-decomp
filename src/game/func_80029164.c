#include "../types.h"

extern u8 D_800EA0E8[];
extern s32 D_8009B0F4;
extern u8 *func_80014EEC(s32, s32, s32, s32, void *, s32, s32);
extern void func_800289BC(void);

void func_80029164(s32 arg0, s32 arg1)
{
    u8 *b = D_800EA0E8;
    u8 *r = &b[arg0 * 64];
    u8 *p;

    *(u16 *)(r + 0x30) = arg1;
    p = func_80014EEC(0, 0, (arg1 - 1) * 7 + 0x2D2, 7, func_800289BC, 0, 0);
    *(s32 *)(p + 0x38) = arg0;
    D_8009B0F4 = *(s32 *)(p + 0x2C) | 0x10;
}
