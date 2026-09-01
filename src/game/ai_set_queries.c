#include "../types.h"

typedef struct {
    s16 card_id;
    u8 pad02[6];
    s8 card_type;
    u8 pad09[3];
} AiActiveCard;

extern AiActiveCard gDuel_aActiveCards[];
extern u8 gAiScript_State[];

s32 Ai_IsCardInSet(s32 arg0)
{
    s32 value;
    s32 i;
    u16 *set;

    value = gDuel_aActiveCards[arg0].card_id;
    set = (u16 *)gAiScript_State;
    for (i = 0; i < 0x20; i++) {
        if (value == set[i + 0x1F])
            return 1;
    }
    return 0;
}

s32 Ai_IsTypeInSet(s32 arg0)
{
    s32 value;
    s32 i;
    u8 *set;

    value = gDuel_aActiveCards[arg0].card_type;
    i = 0;
    set = gAiScript_State;
    for (; i < 0x19; i++) {
        if (value == set[i + 0x7E] - 1)
            return 1;
    }
    return 0;
}
