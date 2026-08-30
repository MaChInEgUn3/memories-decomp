typedef unsigned char u8;

typedef struct {
    u8 pad_00[4];
    u8 field_04;
    u8 field_05;
    u8 field_06;
    u8 field_07;
    u8 pad_08[32];
} State;

extern State D_800E9EC8;
extern u8 D_8009B145;

void func_800151B0(void)
{
    State *state = &D_800E9EC8;

    state->field_06 = 0;
    state->field_04 = 0;
    state->field_05 = 0;
    state->field_07 = 8;
    D_8009B145 = 0;
}
