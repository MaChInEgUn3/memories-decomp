#include "../types.h"

extern s32 gAiScript_aMemory[];
extern s32 AiScript_ReadByte(void);
extern u8 D_800EAE88[];

void AiScript_PlayFaceUp(void) {
    s32 *t = gAiScript_aMemory;
    s32 a = t[AiScript_ReadByte()];
    s32 b = t[AiScript_ReadByte()];
    s32 c = t[AiScript_ReadByte()];
    s32 d = t[AiScript_ReadByte()];
    s32 e = t[AiScript_ReadByte()];

    D_800EAE88[5] = 0;
    D_800EAE88[0] = a;
    D_800EAE88[1] = b;
    D_800EAE88[2] = c;
    D_800EAE88[3] = d;
    D_800EAE88[4] = e;
}
