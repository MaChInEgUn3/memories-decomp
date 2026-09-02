#include "../types.h"

extern u32 D_8009B400;

extern void func_80045334(u32);
extern void func_80047314(u32);
extern void func_800473CC(u32);
extern void func_80047430(s32, s32);
extern void func_80047EC4(void);
extern void SD_SEPlay(u32, s32, s32);

void SD_SEPlayFull(u32 value)
{
    SD_SEPlay(value & 0xFFFF, 0xFF, 0);
}

void func_8003FF08(u32 value)
{
    u32 command = value | 0x7000;

    func_80047314(command & 0xFFFF);
    D_8009B400 = command;
}

void func_8003FF34(void)
{
    func_80047430(-8, 0);
}

void func_8003FF58(s32 value)
{
    if (value > 0)
        value = -value;
    func_80047430((s16)value, 0);
}

void func_8003FF88(u32 value)
{
    SD_SEPlay((value & 0xFFFF) | 0x8000, 0xFF, 0);
}

void func_8003FFB4(u32 value)
{
    func_80045334((value & 0xFFFF) | 0x8000);
}

void func_8003FFD8(u32 value)
{
    func_80047314((value & 0xFFFF) | 0xA000);
}

void func_8003FFFC(void)
{
    func_800473CC(0);
    func_800473CC(0x8000);
    func_80047EC4();
}
