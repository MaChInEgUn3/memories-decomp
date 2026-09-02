#include "../types.h"
#include "sound.h"

extern void func_80049230(short, int);

void func_80049200(int value)
{
    func_80049230((short)value, g_SDValue->field_164B);
}
