#include "../types.h"
#include "ai.h"

extern AiScriptState gAiScript_State;
extern int AiScript_ReadShort(void);

void AiScript_Jump(void)
{
    int result = AiScript_ReadShort();
    register AiScriptState *state = &gAiScript_State;

    state->script_cursor =
        (u8 *)(result + (s32)state->script_base);
}
