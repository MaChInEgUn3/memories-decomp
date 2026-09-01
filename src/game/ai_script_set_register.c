#include "../types.h"

extern int AiScript_ReadByte(void);
extern int gAiScript_aMemory[];

void AiScript_SetRegister(void)
{
    int source = AiScript_ReadByte();
    int destination = AiScript_ReadByte();
    register volatile int *values asm("$3") = gAiScript_aMemory;
    register int value asm("$4");
    volatile int *destination_value = &values[destination];

    value = values[source];
    *destination_value = value;
}
