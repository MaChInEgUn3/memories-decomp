#include "../types.h"

extern u8 *g_SDValue;
extern void func_80047788(u16);

int func_80047B68(u16 value)
{
    u8 *state = g_SDValue;
    if (*(u16 *)(state + 0x442) == value)
        return 1;
    *(u16 *)(state + 0x442) = value;
    *(u16 *)(state + 0x40) |= 2;
    func_80047788(value);
    return 1;
}
