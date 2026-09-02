#include "../types.h"
#include "sound.h"

extern void func_8004733C(unsigned short, unsigned char);

void func_80047314(unsigned int value)
{
    func_8004733C(value & 0xFFFF, g_SDValue->field_164B);
}
