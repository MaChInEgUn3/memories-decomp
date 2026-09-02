#include "../types.h"
#include "sound.h"

void func_8004B6E8(unsigned char index, int value)
{
    register SDSecondaryRecord *entries =
        (SDSecondaryRecord *)D_8009B458;

    entries += index;

    entries->field_0000 = value;
}
