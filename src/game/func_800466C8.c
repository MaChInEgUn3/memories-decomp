typedef unsigned char u8;
typedef unsigned short u16;

extern u8 *D_8009B45C;

void func_800466C8(void)
{
    register u8 *state asm("$3") = D_8009B45C;
    register u8 *flags asm("$4");
    if (*(u16 *)(state + 0x40) & 0x80) {
        *(short *)(state + 0x1588) = 8;
        state[0x1584] = 255;
        asm volatile("" : : : "memory");
        state = D_8009B45C;
    }
    state[0x49] = 0;
    asm volatile("" : : : "memory");
    flags = D_8009B45C;
    *(short *)(state + 0x512) = -64;
    *(u16 *)(flags + 0x40) &= 0xFFFB;
}
