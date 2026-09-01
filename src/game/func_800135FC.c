#include "../types.h"

extern u8 D_800F2848[];
extern s32 func_80086770(s32);
extern s32 func_800866A0(s32);
extern void func_800134E0();

void func_800135FC(void)
{
    u8 *record = D_800F2848;
    s32 distance = -*(s16 *)record;
    s32 x = distance * func_80086770(*(s16 *)(record + 2)) / 4096;
    s32 z = distance * func_800866A0(*(s16 *)(record + 2)) / 4096;
    s32 y = x * func_800866A0(*(s16 *)(record + 4) + 1024) / 4096;
    s32 w = x * func_80086770(*(s16 *)(record + 4) + 1024) / 4096;

    x = w;
    func_800134E0(record, x, y, z);
}
