#include "../types.h"

extern unsigned char D_800F2C40[];
void func_80058FB0(int index, unsigned short *out)
{
    register unsigned int offset asm("$3") = index * 0xE20;
    register unsigned char *base asm("$2") = D_800F2C40;
    asm("" : "+r"(offset), "+r"(base));
    offset += (unsigned int)base;
    out[0] = *(unsigned short *)(offset + 0xDD0);
    out[1] = *(unsigned short *)(offset + 0xDD2);
    out[2] = *(unsigned short *)(offset + 0xDD4);
    out[3] = *(unsigned short *)(offset + 0xDD6);
}
