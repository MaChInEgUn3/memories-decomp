#include "../types.h"

void func_800380D4(u8 *object)
{
    register u8 **stream;
    register u8 *current;
    register u32 value;
    *(u16 *)(object + 0x38) = 0;
    stream = &((u8 **)object)[*(s8 *)(object + 0x58)];
    current = *stream;
    value = current[0];
    current++;
    *stream = current;
    *(u16 *)(object + 0x3A) += (s8)value;
}
