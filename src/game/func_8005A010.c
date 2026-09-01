#include "../types.h"

extern u8 D_800F2B20[];
extern s32 func_8005F174(void);
extern s32 func_8005F18C(void);

void func_8005A010(s32 arg0, s32 arg1)
{
    s32 r = func_8005F174();

    if (r == 1 && func_8005F18C() == r) {
        return;
    }
    {
        u8 *p = D_800F2B20;
        *(u16 *)(p + 0x22) = arg0;
        *(u16 *)(p + 0x2A) = arg1;
    }
}
