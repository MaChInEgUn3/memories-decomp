extern unsigned char *D_8009B458;
extern void func_8004A2F8(void);

void func_80049F10(short first, short second)
{
    unsigned char *state = D_8009B458;

    *(short *)(state + 0x514) = first;
    *(short *)(state + 0x516) = second;
    if (*(short *)(state + 0x7E2) != 2) {
        func_8004A2F8();
    }
}
