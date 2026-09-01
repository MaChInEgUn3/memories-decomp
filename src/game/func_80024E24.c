#include "../types.h"

extern unsigned short D_8009B220;

int func_80024E24(void)
{
    unsigned short value = D_8009B220;

    if (!(value & 0x80)) {
        D_8009B220 = value | 0x80;
        return 0;
    }
    return 1;
}
