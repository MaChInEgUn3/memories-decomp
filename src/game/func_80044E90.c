typedef unsigned char u8;
typedef unsigned short u16;

extern u8 *D_8009B45C;
extern void func_80044DC0(int);

void func_80044E90(int value)
{
    register int saved asm("$5") = value;
    if ((u16)(value - 1) < 128) {
        D_8009B45C[0x514] = -128 - saved;
        D_8009B45C[0x515] = 128;
    } else if ((u16)(value + 128) < 128) {
        D_8009B45C[0x514] = 128;
        D_8009B45C[0x515] = -128 - saved;
    } else {
        D_8009B45C[0x514] = 128;
        D_8009B45C[0x515] = 128;
    }
    func_80044DC0(*(short *)(D_8009B45C + 0x510));
}
