#include "../types.h"

extern u8 *D_8009B458;

extern void func_8004A518(void);
extern void func_8004C77C(void);
extern void func_8004CA60(void);

void func_80049BAC(s32 value)
{
    u8 *state;

    D_8009B458[0x500] = 1;
    state = D_8009B458;
    if (*(s16 *)(state + 0x7E0) == -1) {
        state[0x500] = 0;
    } else {
        u8 *first;
        u8 *second;
        *(s32 *)(state + 0x7EC) = 0x10000;
        *(s32 *)(state + 0x7DC) = *(s32 *)(state + 0x7E8);
        func_8004C77C();
        first = D_8009B458;
        first[0x502] = 1;
        second = D_8009B458;
        *(s32 *)(first + 0x80C) = value;
        *(s16 *)(second + 0x7E2) = 1;
        second[0x500] = 0;
    }
}

void func_80049C40(void)
{
    u8 *initial = D_8009B458;

    if (*(s16 *)(initial + 0x7E0) != -1) {
        u8 *state;
        u8 *other;
        initial[0x500] = 1;
        func_8004CA60();
        func_8004A518();
        state = D_8009B458;
        state[0x500] = 0;
        other = D_8009B458;
        *(s16 *)(state + 0x7E6) = 127;
        *(s16 *)(state + 0x7E4) = 127;
        *(s16 *)(state + 0x7E2) = 2;
        other[0x502] = 0;
    }
}

void func_80049CB0(void)
{
    u8 *state = D_8009B458;

    if (*(s16 *)(state + 0x7E0) != -1) {
        state[0x500] = 1;
        *(s16 *)(D_8009B458 + 0x7E0) = -1;
        *(s16 *)(D_8009B458 + 0x7E2) = 0;
        *(s16 *)(D_8009B458 + 0x7E6) = 127;
        *(s16 *)(D_8009B458 + 0x7E4) = 127;
        D_8009B458[0x500] = 0;
    }
}
