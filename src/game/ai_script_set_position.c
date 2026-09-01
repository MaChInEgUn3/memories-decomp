#include "../types.h"

extern s32 gAiScript_aMemory[];
extern u8 D_800EAE8E[];
extern s32 AiScript_ReadByte(void);

void AiScript_SetPosition(void)
{
    s32 *p = gAiScript_aMemory;
    s32 v;

    v = p[AiScript_ReadByte()];
    D_800EAE8E[0] = v;
}
