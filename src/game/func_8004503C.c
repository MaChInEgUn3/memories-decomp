#include "../types.h"
#include "sound.h"

void func_8004503C(short value, unsigned char flag)
{
    g_SDValue->field_0512 = value;
    g_SDValue->field_0049 = flag;
}
