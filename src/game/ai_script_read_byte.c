#include "../types.h"

typedef struct {
    unsigned char padding[8];
    unsigned char *current;
} ByteStream;

extern ByteStream gAiScript_State;

int AiScript_ReadByte(void)
{
    // Preserve the original stream-base register allocation.
    register ByteStream *stream = &gAiScript_State;

    return *stream->current++;
}
