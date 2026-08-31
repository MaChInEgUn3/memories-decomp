typedef unsigned char u8;

extern u8 *D_8009B458;
extern void func_800771B0(void *);
extern int func_80077150(int, int);

int func_800497E0(int value, unsigned int amount, short expected)
{
    register u8 *state asm("$3") = D_8009B458;
    short current = *(short *)(state + 0x4A4);
    register int result asm("$2");
    u8 *entry;
    unsigned int remaining;
    if (current != expected)
        goto failure;
    entry = state + 0x4A4;
    func_800771B0((u8 *)*(void **)(entry + 0x14) +
                  *(unsigned int *)(state + 0x818));
    remaining = *(unsigned int *)(entry + 0x10) -
                *(unsigned int *)(D_8009B458 + 0x818);
    if (remaining < amount)
        amount = remaining;
    if (func_80077150(value, amount) == amount)
        goto success;
failure:
    result = -1;
    goto done;
success:
    {
        register u8 *final asm("$2") = D_8009B458;
        *(unsigned int *)(final + 0x818) += amount;
        if (*(unsigned int *)(final + 0x818) <
            *(unsigned int *)(entry + 0x10))
            result = -2;
        else
            result = current;
    }
done:
    return result;
}
