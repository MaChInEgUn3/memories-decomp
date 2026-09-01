#include "../types.h"

extern int AiScript_ReadByte(void);
extern int AiScript_ReadShort(void);
extern int gAiScript_aMemory[];

void AiScript_Store(void)
{
    int value = AiScript_ReadShort();
    int index = AiScript_ReadByte();
    volatile int *values = gAiScript_aMemory;

    values[index] = value;
}
