#include "../types.h"

typedef struct { u8 pad[20]; s16 value; u8 tail[10]; } Rec32;
extern s32 gAiScript_aMemory[];
extern Rec32 D_800E9FF0[];
extern s32 AiScript_ReadByte(void);
void AiScript_LoadLifePoint(void) {
    s32 *p = gAiScript_aMemory;
    s32 i = p[AiScript_ReadByte()];
    p[AiScript_ReadByte()] = D_800E9FF0[1 - i].value;
}
