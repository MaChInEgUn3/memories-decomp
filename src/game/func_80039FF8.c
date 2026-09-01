#include "../types.h"

void func_80039FF8(u8 *object)
{
    u8 flags = object[0x32];
    if ((flags & 3) == 0) {
        object[0x32] = flags | 0x10;
        object[0x33] = 0;
    }
}
