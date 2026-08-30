typedef unsigned char u8;

typedef struct {
    u8 pad_00[6];
    u8 field_06;
    u8 field_07;
    u8 pad_08[32];
} State;

extern State D_800E9EC8;
extern void func_80015780(void);
extern void func_8001572C(void);

void func_800157DC(void)
{
    State *state;

    func_80015780();
    state = &D_800E9EC8;
    state->field_07 = 8;
    state->field_06 |= 1;
    func_8001572C();
}
