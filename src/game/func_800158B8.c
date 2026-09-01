#include "../types.h"

typedef struct {
    int field_00;
    u8 field_04;
    u8 field_05;
    u8 field_06;
    u8 field_07;
    unsigned short field_08;
} State;

extern State D_800E9EC8;
extern void func_800156B8(u8);
extern void func_80015870(void);

void func_800158B8(void)
{
    State *state = &D_800E9EC8;

    state->field_08 = 0xFF;
    state->field_05 = 0;
    state->field_06 = 0x80;
    func_800156B8(state->field_04);
    state->field_07 = 0xC;
    func_80015870();
}
