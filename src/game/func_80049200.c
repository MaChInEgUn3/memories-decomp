#include "../types.h"

extern u8 *g_SDValue;
extern void func_80049230(short, int);

void func_80049200(int value)
{
    func_80049230((short)value, g_SDValue[0x164B]);
}
