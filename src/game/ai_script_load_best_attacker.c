#include "../types.h"

extern int gAiScript_aMemory[];
extern unsigned char gAi_bBestAttacker;
extern int AiScript_ReadByte(void);

void AiScript_LoadBestAttacker(void)
{
    int index = AiScript_ReadByte();
    register int *values asm("$4") = gAiScript_aMemory;
    register unsigned int value asm("$3");

    asm("" : "+r"(values));
    value = gAi_bBestAttacker;
    values[index] = value;
}
