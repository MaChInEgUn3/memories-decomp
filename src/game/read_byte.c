typedef struct {
    unsigned char padding[8];
    unsigned char *current;
} ByteStream;

extern ByteStream D_800F5BE8;

int func_8007058C(void)
{
    // Preserve the original stream-base register allocation.
    register ByteStream *stream asm("$3") = &D_800F5BE8;

    return *stream->current++;
}
