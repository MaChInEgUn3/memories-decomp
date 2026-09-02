#include "../types.h"
#include "sound.h"

void func_80046990(int first, int second, int third)
{
    g_SDValue->field_003C = 0;
    if (first == 0)
        g_SDValue->flags_004A &= 0xFE;
    if (second == 0)
        g_SDValue->flags_004A &= 0xFD;
    if (third == 0)
        g_SDValue->flags_004A &= 0xBF;
    g_SDValue->flags_0040 |= 0xA;
}
