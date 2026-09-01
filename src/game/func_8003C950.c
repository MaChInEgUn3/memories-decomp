#include "../types.h"

extern u8 D_801AF000[];
extern s32 D_8009B378;
extern u8 D_800E9ECF[];
extern s32 func_8004002C(void);
extern u8 *func_800400AC();
extern void func_80040510();
extern void func_800428A8();
extern void func_800428EC();
extern void func_800429D8();
extern void func_8003FF08();
extern void func_800157DC();

void func_8003C950(void)
{
    u8 *object;
    object = func_800400AC(func_8004002C(), 3);
    func_80040510(object, 0, 0, 320, 240, 0, 0, 16, 0, 240);
    *(s32 *)(object + 4) |= 0x1000000;
    object = func_800400AC(func_8004002C(), 2);
    func_800428A8(object, 448, 192, 0, 0, 0, 18, 1, D_801AF000);
    object[94] = 128;
    func_800428EC(object, 4);
    object[108] = 0;
    *(u16 *)(object + 8) |= 40;
    func_800429D8(object);
    D_8009B378 = (s32)object;
    func_8003FF08(0x7300);
    func_800157DC();
    D_800E9ECF[0] = 2;
}
