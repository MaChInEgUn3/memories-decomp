#include "../types.h"

typedef struct {
    s16 unk0;
    u8 pad2[6];
    s8 unk8;
    u8 pad9[3];
} EntryC;

extern EntryC gDuel_aActiveCards[];
extern u8 gAiScript_State[];

s32 Ai_IsTypeInSet(s32 arg0)
{
    s32 v;
    s32 i;
    u8 *q;

    v = gDuel_aActiveCards[arg0].unk8;
    i = 0;
    q = gAiScript_State;
    for (; i < 0x19; i++) {
        if (v == q[i + 0x7E] - 1) {
            return 1;
        }
    }
    return 0;
}
