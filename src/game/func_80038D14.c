#include "../types.h"

extern u32 D_8009B350;

void func_80038D14(u8 *value)
{
    value[0x51] = 4;
    D_8009B350 = 1;
}
