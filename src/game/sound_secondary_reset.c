#include "../types.h"

extern u8 *D_8009B458;
extern s16 func_80077240(s32);

s16 func_800498BC(s16 arg0)
{
    if (arg0 == 0)
        return func_80077240(0);
    return func_80077240(1);
}

void func_800498F8(void)
{
    s16 *value = (s16 *)(D_8009B458 + 0x4A4);

    if (*value != -1)
        *value = -1;
}
