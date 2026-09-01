#include "../types.h"

typedef struct {
    int field_00;
    u8 field_04;
    u8 field_05;
    u8 field_06;
    u8 field_07;
    u8 pad_08[4];
} State;

extern u8 D_8009B142;
extern u8 D_8009B143;
extern u8 D_8009B144;
extern u8 D_8009B145;
extern u8 D_8009B14A;
extern u8 D_8009B14B;
extern u8 D_8009B14C;
extern State D_800E9EC8;

void func_8001572C(void)
{
    State *state;
    int value;
    if (D_8009B145 != 0) {
        value = 0xFFFFFF;
        state = &D_800E9EC8;
        state->field_00 = value;
        state->field_06 = 0x90;
        state->field_07 = 0xC;
        D_8009B14C = 1;
        D_8009B144 = 1;
        D_8009B14B = 1;
        D_8009B143 = 1;
        D_8009B14A = 1;
        D_8009B142 = 1;
    }
}
