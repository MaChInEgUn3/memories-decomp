#include "../types.h"

extern u8 *D_8009B328;
void func_80037914(u8 *object)
{
    u8 flags = D_8009B328[0x32];
    if ((flags & 3) == 0) {
        D_8009B328[0x32] = flags | 0x10;
        D_8009B328[0x33] = 6;
        object[0x51] = 8;
    }
}
