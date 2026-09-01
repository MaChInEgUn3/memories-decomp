#include "../types.h"

typedef struct { s16 value; u8 pad[10]; } Rec12;
extern s32 gAiScript_aMemory[];
extern Rec12 gDuel_aActiveCards[];
extern s32 AiScript_ReadByte(void);
void AiScript_LoadCardID(void) {
    s32 *p = gAiScript_aMemory;
    s32 i = p[AiScript_ReadByte()];
    p[AiScript_ReadByte()] = gDuel_aActiveCards[i].value;
}
