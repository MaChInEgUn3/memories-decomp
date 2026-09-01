typedef unsigned char u8;
typedef unsigned short u16;

extern u8 *g_SDValue;

void func_800466C8(void)
{
    register u8 *state asm("$3") = g_SDValue;
    register u8 *flags asm("$4");
    if (*(u16 *)(state + 0x40) & 0x80) {
        *(short *)(state + 0x1588) = 8;
        state[0x1584] = 255;
        asm volatile("" : : : "memory");
        state = g_SDValue;
    }
    state[0x49] = 0;
    asm volatile("" : : : "memory");
    flags = g_SDValue;
    *(short *)(state + 0x512) = -64;
    *(u16 *)(flags + 0x40) &= 0xFFFB;
}
