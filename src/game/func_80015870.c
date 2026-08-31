typedef unsigned char u8;

typedef struct {
    int field_00;
    u8 field_04;
    u8 field_05;
    u8 field_06;
    u8 field_07;
    u8 pad_08[4];
} State;

extern u8 D_8009B145;
extern u8 D_8009B14A;
extern u8 D_8009B14B;
extern u8 D_8009B14C;
extern State D_800E9EC8;

void func_80015870(void)
{
    State *state;
    int value;
    if (D_8009B145 != 0) {
        value = 0xFFFFFF;
        state = &D_800E9EC8;
        state->field_00 = value;
        state->field_06 = 0xB0;
        state->field_07 = 0xC;
        D_8009B14A = 0xFF;
        D_8009B14B = 0xFF;
        D_8009B14C = 0xFF;
    }
}
