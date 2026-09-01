#include "../types.h"

extern int gAiScript_aMemory[];
extern unsigned char D_800EAE90;
extern int AiScript_ReadByte(void);

void func_80071510(void)
{
    int index = AiScript_ReadByte();
    register int *values asm("$4") = gAiScript_aMemory;
    register unsigned int value asm("$3");

    asm("" : "+r"(values));
    value = D_800EAE90;
    values[index] = value;
}
