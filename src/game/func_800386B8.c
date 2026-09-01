#include "../types.h"

extern s32 D_8009B404[];
extern s32 D_8009B400[];
extern s32 D_8009B350;
extern s32 func_80036D3C();
extern void func_8003FF08();

void func_800386B8(u8 *state)
{
    u8 **slot = (u8 **)(state + *(s8 *)(state + 88) * 4);
    u8 *stream = *slot;
    s32 command = *stream;
    s32 op;

    *slot = stream + 1;
    op = command;
    if (op & 63) {
        func_8003FF08(func_80036D3C(state) & 65535);
    } else {
        if (op & 1)
            func_8003FF08(D_8009B404[0]);
        if (op & 2)
            D_8009B404[0] = func_80036D3C(state) & 65535;
        if (op & 4)
            D_8009B404[0] = D_8009B400[0];
    }
    if (op & 128) {
        state[81] = 12;
        D_8009B350 = 1;
    }
}
