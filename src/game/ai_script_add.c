#include "../types.h"

extern int AiScript_ReadByte(void);
extern int gAiScript_aMemory[];

void AiScript_Add(void)
{
    int left = AiScript_ReadByte();
    int right = AiScript_ReadByte();
    int output = AiScript_ReadByte();
    int *values = gAiScript_aMemory;

    values[output] = values[left] + values[right];
}
