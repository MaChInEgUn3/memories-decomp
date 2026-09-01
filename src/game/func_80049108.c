#include "../types.h"

extern unsigned char *g_SDValue;
void func_80049108(short value, unsigned char flag)
{
    *(short *)(g_SDValue + 0x1582) = value;
    g_SDValue[0x1584] = flag;
}
