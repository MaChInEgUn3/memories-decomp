typedef unsigned char u8;

typedef struct {
    u8 pad_00[4];
    u8 field_04;
    u8 field_05;
    u8 field_06;
    u8 pad_07[3];
    u8 field_0A[30];
} State;

extern State D_800E9EC8;

void func_80015BF0(int value)
{
    State *state = &D_800E9EC8;

    state->field_04 = value;
    state->field_05 = value;
    state->field_06 = 0x80;
}
