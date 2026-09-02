#include "../types.h"
#include "ai.h"

extern AiScriptState gAiScript_State;

int AiScript_ReadShort(void)
{
    // Preserve the original stream and increment register allocation.
    register AiScriptState *stream asm("$2") = &gAiScript_State;
    unsigned char *current = stream->script_cursor;
    register unsigned char *next asm("$4") = current + 2;

    stream->script_cursor = next;
    return current[0] | (current[1] << 8);
}
