#include "../types.h"

extern void func_80045114(void);
extern void func_800490F0(s16, u8);
extern void func_80049108(s16, u8);
extern void func_80049230(s32, s16);

void func_800473F0(u16, s32);

void func_800473CC(u32 value)
{
    func_800473F0(value & 0xFFFF, -32);
}

void func_800473F0(u16 flags, s32 value)
{
    if ((flags & 0x8000) != 0)
        func_80045114();
    else
        func_80049230(-1, value);
}

void func_80047430(s32 value, s32 flag)
{
    func_80049108(value, flag);
}

void func_80047458(s32 value, s32 flag)
{
    func_800490F0(value, flag);
}
