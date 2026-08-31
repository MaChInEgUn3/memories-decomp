typedef unsigned char u8;

typedef struct {
    int field_00;
    u8 field_04;
    u8 field_05;
    u8 field_06;
    u8 field_07;
    unsigned short field_08;
} State;

extern u8 D_8009B141;
extern State D_800E9EC8;
extern void func_800156B8(u8);
extern void func_8001572C(void);

void func_80015780(void)
{
    State *state = &D_800E9EC8;

    state->field_05 = 0xFF;
    state->field_06 = 0x80;
    D_8009B141 &= 0x7F;
    state->field_08 = 0;
    func_800156B8(state->field_04);
    state->field_07 = 0xC;
    func_8001572C();
}
