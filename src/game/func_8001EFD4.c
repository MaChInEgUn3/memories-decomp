#include "../types.h"

extern u8 D_801A7AD8[];
extern s32 Duel_CalcCardStats();
extern s32 Duel_CalcBattleDefense();
extern s32 Duel_CalcBattleAttack();

s32 func_8001EFD4(u8 *left, u8 *right)
{
    u8 *a = D_801A7AD8 + left[106] * 28;
    u8 *b;
    s32 packed;
    s32 wanted;
    s32 actual;

    if (right == (u8 *)0)
        return Duel_CalcCardStats(a) & 65535;
    b = D_801A7AD8 + right[106] * 28;
    packed = Duel_CalcCardStats(b);
    wanted = packed & 65535;
    if (*(u16 *)(b + 22) & 2048)
        wanted = (u32)packed >> 16;
    if (*(u16 *)(a + 22) & 2048)
        actual = Duel_CalcBattleDefense(a, b);
    else
        actual = Duel_CalcBattleAttack(a, b);
    if (actual != wanted)
        return actual - wanted;
    if ((*(u16 *)(a + 22) & 2048) || (*(u16 *)(b + 22) & 2048))
        return 0;
    return -1;
}
