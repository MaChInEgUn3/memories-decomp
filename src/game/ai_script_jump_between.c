#include "../types.h"

extern s32 gAiScript_aMemory[];
extern s32 gAiScript_State[];
extern s32 AiScript_ReadByte();
extern s32 AiScript_ReadShort();

void AiScript_JumpBetween(void)
{
    s32 first = AiScript_ReadByte();
    s32 second = AiScript_ReadByte();
    s32 third = AiScript_ReadByte();
    s32 offset = AiScript_ReadShort();
    s32 value = gAiScript_aMemory[first];
    if (value <= gAiScript_aMemory[second] &&
        gAiScript_aMemory[third] <= value) {
        offset += gAiScript_State[1];
        gAiScript_State[2] = offset;
    }
}
