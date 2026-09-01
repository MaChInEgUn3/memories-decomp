#include "../types.h"

extern unsigned char *D_8009B458;
void func_80049594(int value)
{
    *(int *)(D_8009B458 + 0x81C) = value;
}
