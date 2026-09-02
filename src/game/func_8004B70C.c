#include "../types.h"
#include "sound.h"

void func_8004B70C(unsigned char index, int unused, int value)
{
    register SDSecondaryRecord *entries =
        (SDSecondaryRecord *)D_8009B458;

    entries += index;

    entries->field_0007 = value & 0x7F;
}
