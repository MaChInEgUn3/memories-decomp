#include "../types.h"

extern void AiScript_ReadByte(void);

void AiScript_SkipHand(void)
{
    AiScript_ReadByte();
    AiScript_ReadByte();
    AiScript_ReadByte();
    AiScript_ReadByte();
}
