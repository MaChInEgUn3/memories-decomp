typedef unsigned char u8;

extern u8 *D_8009B458;
extern void func_800771B0(void *);
extern int func_80077150(int, int);

int func_8004975C(int value, short expected)
{
    register int saved;
    u8 *state = D_8009B458;
    short current = *(short *)(state + 0x4A4);
    if (current != expected)
        return -1;
    saved = value;
    {
        u8 *entry = state + 0x4A4;
        func_800771B0(*(void **)(entry + 0x14));
        if (func_80077150(saved, *(int *)(entry + 0x10)) !=
            *(int *)(entry + 0x10))
            return -1;
        *(int *)(entry + 0x0C) = saved;
    }
    return current;
}
