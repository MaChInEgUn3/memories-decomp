#include "../types.h"
#include "ai.h"

extern s32 AiScript_ReadByte(void);
void AiScript_LoadLifePoint(void) {
    s32 *p = gAiScript_aMemory;
    s32 i = p[AiScript_ReadByte()];
    p[AiScript_ReadByte()] = D_800E9FF0[1 - i].life_points;
}
