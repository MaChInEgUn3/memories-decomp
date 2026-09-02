#include "../types.h"
#include "ai.h"

extern u8 D_800EAE90;
extern u8 D_800F5C7F;

extern s32 AiScript_ReadByte(void);

void func_80073448(void)
{
    D_800EAE90 = 1;
}

void func_80073458(void)
{
    D_800EAE90 = 0;
}

void func_80073464(void)
{
    D_800F5C7F = 1;
}

void func_80073474(void)
{
    D_800F5C7F = 0;
}

void AiScript_MoveCard(void)
{
    register s32 *values = gAiScript_aMemory;
    s32 index = AiScript_ReadByte();
    s32 value = values[index];

    gDuel_aActiveCards[value].flags |= 0x4000;
}
