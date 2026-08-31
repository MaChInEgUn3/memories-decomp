typedef unsigned char u8;

extern u8 *D_8009B458;

void func_80049CB0(void)
{
    u8 *state = D_8009B458;
    if (*(short *)(state + 0x7E0) != -1) {
        state[0x500] = 1;
        *(short *)(D_8009B458 + 0x7E0) = -1;
        *(short *)(D_8009B458 + 0x7E2) = 0;
        *(short *)(D_8009B458 + 0x7E6) = 127;
        *(short *)(D_8009B458 + 0x7E4) = 127;
        D_8009B458[0x500] = 0;
    }
}
