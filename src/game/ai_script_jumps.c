#include "../types.h"

typedef struct {
    s32 first;
    s32 addend;
    s32 result;
} AiScriptCursor;

extern s32 gAiScript_aMemory[];
extern AiScriptCursor gAiScript_State;

extern s32 AiScript_ReadByte(void);
extern s32 AiScript_ReadShort(void);
extern s32 func_8008E590(void);

void AiScript_JumpBetween(void)
{
    s32 first = AiScript_ReadByte();
    s32 second = AiScript_ReadByte();
    s32 third = AiScript_ReadByte();
    s32 offset = AiScript_ReadShort();
    s32 value = gAiScript_aMemory[first];

    if (
        value <= gAiScript_aMemory[second] &&
        gAiScript_aMemory[third] <= value
    ) {
        offset += gAiScript_State.addend;
        gAiScript_State.result = offset;
    }
}

void AiScript_JumpRandom(void)
{
    register s32 *values = gAiScript_aMemory;
    register s32 limit;
    register s32 result;
    s32 index = AiScript_ReadByte();

    limit = values[index];
    result = AiScript_ReadShort();
    if (func_8008E590() % 100 < limit) {
        result += gAiScript_State.addend;
        gAiScript_State.result = result;
    }
}
