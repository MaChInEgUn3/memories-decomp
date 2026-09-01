#include "../types.h"

extern unsigned char *g_SDValue;
void func_8004503C(short value, unsigned char flag)
{
    *(short *)(g_SDValue + 0x512) = value;
    g_SDValue[0x49] = flag;
}
