typedef unsigned char u8;

typedef struct {
    u8 pad_00[6];
    u8 field_06;
    u8 field_07;
    u8 pad_08[32];
} State;

extern State D_800E9EC8;
extern void func_800158B8(void);
extern void func_80015870(void);

void func_80015904(void)
{
    State *state;

    func_800158B8();
    state = &D_800E9EC8;
    state->field_07 = 8;
    state->field_06 |= 1;
    func_80015870();
}
