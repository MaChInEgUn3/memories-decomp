#include "../types.h"
#include "ai.h"

extern AiScriptState gAiScript_State;

int AiScript_ReadByte(void)
{
    // Preserve the original stream-base register allocation.
    register AiScriptState *stream = &gAiScript_State;

    return *stream->script_cursor++;
}
