typedef unsigned char u8;

typedef struct {
    u8 pad_00[6];
    u8 field_06;
    u8 pad_07[33];
} State;

extern State D_800E9EC8;
extern void func_80015780(void);
extern void func_8001572C(void);

void func_80015C0C(void)
{
    State *state;

    func_80015780();
    state = &D_800E9EC8;
    state->field_06 |= 2;
    func_8001572C();
}
