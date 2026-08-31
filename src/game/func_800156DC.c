typedef unsigned char u8;

typedef struct {
    int field_00;
    u8 field_04;
    u8 field_05;
    u8 field_06;
    u8 field_07;
    unsigned short field_08;
} State;

extern u8 D_8009B142;
extern u8 D_8009B143;
extern u8 D_8009B144;
extern u8 D_8009B145;
extern State D_800E9EC8;
extern void func_800158B8(void);
extern void func_80015D0C(void);

void func_800156DC(void)
{
    State *state;
    D_8009B145 = 1;
    func_800158B8();
    state = &D_800E9EC8;
    state->field_06 = 0;
    state->field_04 = 0;
    D_8009B142 = 0xFF;
    D_8009B143 = 0xFF;
    D_8009B144 = 0xFF;
    func_80015D0C();
}
