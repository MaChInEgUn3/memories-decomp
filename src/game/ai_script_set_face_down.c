#include "../types.h"
#include "ai.h"

extern s32 AiScript_ReadByte(void);

/* Looks up gDuel_aActiveCards[gAiScript_aMemory[idx1]] and classifies it: 0 if field0 is
   zero, 2 if flags bit 0x1000 is set, else 1. Stores the result at
   gAiScript_aMemory[idx2]. */
void AiScript_SetFaceDown(void) {
    s32 *table = gAiScript_aMemory;
    s32 idx1 = AiScript_ReadByte();
    s32 val1 = table[idx1];
    s32 idx2 = AiScript_ReadByte();
    s32 flagval;

    if (gDuel_aActiveCards[val1].card_id == 0) {
        flagval = 0;
    } else if (gDuel_aActiveCards[val1].flags & 0x1000) {
        flagval = 2;
    } else {
        flagval = 1;
    }

    gAiScript_aMemory[idx2] = flagval;
}
