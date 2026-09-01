#include "../types.h"

typedef struct {
    int field_00;
    u8 field_04;
    u8 field_05;
    u8 field_06;
    u8 field_07;
    u8 pad_08[4];
} State;

extern u8 D_8009B145;
extern int D_800E9EC8[3];
extern void func_800158B8(void);
extern void func_80015870(void);

void func_80015944(int arg0)
{
    State *state;

    if (arg0 == 0xFFFFFF) {
        D_8009B145 = 1;
    }
    D_800E9EC8[0] = arg0;
    func_800158B8();
    state = (State *)D_800E9EC8;
    state->field_06 |= 0x30;
    func_80015870();
}
