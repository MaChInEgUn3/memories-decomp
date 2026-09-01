typedef unsigned char u8;
typedef unsigned short u16;

extern u8 *g_SDValue;
extern void func_80077450(void *);

void func_80047864(int index)
{
    register int saved asm("$5");
    asm volatile("move %0,%1" : "=r"(saved) : "r"(index));
    {
        register unsigned int mask asm("$3") = 0x00100000;
        u8 *state;
        register u8 *half asm("$3");
        register u8 *byte asm("$6");
        unsigned int product;
        if (saved != 0)
            mask <<= saved;
        state = g_SDValue;
        *(unsigned int *)(state + 0x3C4) = mask;
        half = state + (saved << 1);
        byte = state + saved;
        *(int *)(state + 0x3C8) = 3;
        {
            register unsigned int first asm("$5") =
                *(u16 *)(half + 0x414);
            product = first * (unsigned int)byte[0x424];
        }
        *(u16 *)(state + 0x3CC) = product >> 8;
        product = *(u16 *)(half + 0x41C) * (unsigned int)byte[0x424];
        *(u16 *)(state + 0x3CE) = product >> 8;
        func_80077450(state + 0x3C4);
    }
}
