#include "../types.h"

extern int gAiScript_aMemory[];
extern unsigned char gAi_bBestTarget;
extern int AiScript_ReadByte(void);

void AiScript_LoadBestTarget(void)
{
    int index = AiScript_ReadByte();
    register int *values asm("$4") = gAiScript_aMemory;
    register unsigned int value asm("$3");

    asm("" : "+r"(values));
    value = gAi_bBestTarget;
    values[index] = value;
}
