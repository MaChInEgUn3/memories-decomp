#include "../types.h"

void func_80038110(u8 *object)
{
    u8 **stream = &((u8 **)object)[*(s8 *)(object + 0x58)];
    register u8 **slot = stream;
    register u8 *current = *slot;
    register u32 value = current[0];
    current++;
    *slot = current;
    *(u16 *)(object + 0x38) += value;
}
