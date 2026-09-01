#include "../types.h"

int func_80039AAC(u8 *object)
{
    u8 flags = object[0x13];
    if ((flags & 0x80) == 0) {
        object[0x13] = flags | 0x80;
        return 0;
    }
    return 1;
}
