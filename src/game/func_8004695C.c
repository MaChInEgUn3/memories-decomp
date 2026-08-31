extern unsigned char *volatile D_8009B458;

void func_8004695C(int value)
{
    unsigned char *state;

    D_8009B458[0x509] = value;
    state = D_8009B458;
    if (state[0x509] != 0) {
        state[0x500] = 1;
    } else {
        state[0x500] = 0;
    }
}
