#include "../types.h"

extern unsigned char *g_SDValue;
int func_8004703C(void)
{
    return *(short *)(g_SDValue + 0x40);
}
