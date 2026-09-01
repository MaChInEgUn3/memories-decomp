#include "../types.h"

int func_80033500(u8 *object)
{
    s32 index = *(s16 *)(object + 0x2D3C) + *(s8 *)(object + 0x2D48);
    u8 *entry = object + index * 0x10;
    if (entry[0xD] == 0) {
        return 0;
    }
    return *(s16 *)(entry + 4);
}
