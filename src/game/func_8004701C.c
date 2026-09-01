#include "../types.h"

extern unsigned char *g_SDValue;
void func_8004701C(int value)
{
    g_SDValue[0x4A] = (g_SDValue[0x4A] & 0xF0) | value;
}
