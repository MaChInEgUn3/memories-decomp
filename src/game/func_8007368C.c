#include "../types.h"

extern s32 gAiScript_aMemory[];
extern u8 D_800EAE8F[];
extern s32 AiScript_ReadByte(void);

void func_8007368C(void)
{
    D_800EAE8F[0] = *(u8 *)&gAiScript_aMemory[AiScript_ReadByte()];
}
