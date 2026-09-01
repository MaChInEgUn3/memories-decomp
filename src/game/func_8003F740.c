#include "../types.h"

extern unsigned char D_8009B3C1;
extern unsigned char D_8009B3DE;
extern unsigned short D_8009B3FA;

void func_8003F740(unsigned char value)
{
    D_8009B3FA = 0x8000;
    D_8009B3DE = value;
    D_8009B3C1 = 0;
}
