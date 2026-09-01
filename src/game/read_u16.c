typedef struct {
    unsigned char padding[8];
    unsigned char *current;
} ByteStream;

extern ByteStream gAiScript_State;

int func_800705AC(void)
{
    // Preserve the original stream and increment register allocation.
    register ByteStream *stream asm("$2") = &gAiScript_State;
    unsigned char *current = stream->current;
    register unsigned char *next asm("$4") = current + 2;

    stream->current = next;
    return current[0] | (current[1] << 8);
}
