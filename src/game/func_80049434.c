#include "../types.h"

extern u8 *D_8009B458;

void func_80049434(void)
{
    u8 *state;
    u8 *other;
    u8 *third;
    u8 *fourth;
    u8 *fifth;
    u8 *final;
    D_8009B458[0x500] = 0;
    D_8009B458[0x501] = 0;
    D_8009B458[0x502] = 0;
    state = D_8009B458;
    *(short *)(state + 0x510) = 20;
    state[0x814] = 0;
    other = D_8009B458;
    *(short *)(state + 0x512) = 127;
    *(short *)(state + 0x514) = 127;
    *(short *)(state + 0x516) = 127;
    other[0x815] = 0;
    third = D_8009B458;
    third[0x4BD] = 127;
    fourth = D_8009B458;
    *(short *)(third + 0x4A4) = -1;
    fourth[0x4BE] = 127;
    fifth = D_8009B458;
    fifth[0x4BF] = 64;
    final = D_8009B458;
    *(short *)(final + 0x7E0) = -1;
    *(short *)(final + 0x7E2) = 0;
    *(short *)(final + 0x7E6) = 127;
    *(short *)(final + 0x7E4) = 127;
    *(int *)(final + 0x80C) = 0;
    *(int *)(final + 0x810) = 0;
    *(int *)(final + 0x81C) = 0x1000;
}
