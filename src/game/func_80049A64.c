typedef unsigned char u8;

extern u8 *D_8009B458;

int func_80049A64(void *input, short value)
{
    unsigned int tag;
    u8 *state;
    D_8009B458[0x500] = 1;
    tag = *(unsigned int *)input;
    if (tag != 0x53455170 && tag != 0x6468544D &&
        tag != 0x2054444B && tag != 0x3154444B)
        return -1;
    state = D_8009B458;
    if (*(short *)(state + 0x7E0) == -1) {
        *(void **)(state + 0x7E8) = input;
        *(short *)(state + 0x7E0) = value;
        *(short *)(state + 0x7E2) = 2;
        state[0x500] = 0;
        return 0;
    }
    state[0x500] = 0;
    return -1;
}
