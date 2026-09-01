#include "../types.h"

extern s16 func_80077240(s32);

s16 func_800498BC(s16 arg0)
{
    if (arg0 == 0) {
        return func_80077240(0);
    }
    return func_80077240(1);
}
