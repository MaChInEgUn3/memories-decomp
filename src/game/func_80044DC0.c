typedef unsigned char u8;
typedef unsigned short u16;

extern u8 *D_8009B45C;
extern void func_8007CDC0(u8 *);

void func_80044DC0(int value)
{
    register u8 *state asm("$5") = D_8009B45C;
    register int base asm("$6");
    register int color asm("$3");
    register int narrowed asm("$2");
    register int saved asm("$16");
    u8 data[4];
    int product;
    product = ((short)value + 1) * *(u16 *)(state + 0x42);
    product = state[0x533] * (product >> 8);
    narrowed = (u16)product;
    base = narrowed >> 3;
    color = state[0x514];
    product = base * color;
    data[3] = 0;
    data[0] = product >> 7;
    saved = value;
    if (state[0x48] == 0) {
        data[1] = 0;
        product = base * state[0x515];
        data[2] = product >> 7;
    } else {
        product = base * state[0x515];
        data[2] = 0;
        data[1] = product >> 7;
    }
    func_8007CDC0(data);
    *(short *)(D_8009B45C + 0x510) = saved;
}
