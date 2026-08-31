typedef unsigned char u8;

extern u8 *D_8009B458;
extern void func_8004C77C(void);

void func_80049BAC(int value)
{
    u8 *state;
    D_8009B458[0x500] = 1;
    state = D_8009B458;
    if (*(short *)(state + 0x7E0) == -1) {
        state[0x500] = 0;
    } else {
        u8 *first;
        u8 *second;
        *(int *)(state + 0x7EC) = 0x10000;
        *(int *)(state + 0x7DC) = *(int *)(state + 0x7E8);
        func_8004C77C();
        first = D_8009B458;
        first[0x502] = 1;
        second = D_8009B458;
        *(int *)(first + 0x80C) = value;
        *(short *)(second + 0x7E2) = 1;
        second[0x500] = 0;
    }
}
