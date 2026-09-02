#include "../types.h"

extern u8 *D_8009B458;

extern void func_8004A2F8(void);
extern s32 func_8004CABC(void);

void func_80049EC8(s32 arg0, s32 arg1)
{
    u8 *state = D_8009B458;
    s32 mode = *(s16 *)(state + 0x7E2);

    *(s16 *)(state + 0x7E4) = arg0 & 0x7F;
    *(s16 *)(state + 0x7E6) = arg1 & 0x7F;
    if (mode != 2)
        func_8004A2F8();
}

void func_80049F10(s16 first, s16 second)
{
    u8 *state = D_8009B458;

    *(s16 *)(state + 0x514) = first;
    *(s16 *)(state + 0x516) = second;
    if (*(s16 *)(state + 0x7E2) != 2)
        func_8004A2F8();
}

s32 func_80049F50(void)
{
    s32 value;

    if (*(s16 *)(D_8009B458 + 0x7E2) == 1) {
        value = (s16)func_8004CABC();
        if (value == 3)
            *(s16 *)(D_8009B458 + 0x7E2) = value;
    }
    return *(s16 *)(D_8009B458 + 0x7E2);
}
