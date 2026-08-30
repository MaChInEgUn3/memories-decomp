typedef unsigned char u8;

typedef struct {
    u8 pad_00[6];
    u8 field_06;
    u8 pad_07[33];
} State;

extern State D_800E9EC8;
extern void func_80012D4C(void);

void func_80015998(void)
{
    State *state = &D_800E9EC8;

    do {
        func_80012D4C();
    } while (state->field_06 & 0x80);
}
