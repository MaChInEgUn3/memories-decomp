#include "../types.h"

extern unsigned char D_8009B248;

int func_800282E8(void)
{
    unsigned char value = D_8009B248;

    if (!(value & 0x80)) {
        D_8009B248 = value | 0x80;
        return 0;
    }
    return 1;
}
