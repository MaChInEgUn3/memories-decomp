#include "../types.h"

extern u32 D_8009B300;
extern u32 D_8009B30C;

void func_80035668(u32 value)
{
    D_8009B30C = value;
    D_8009B300 = 0x808080;
}
