typedef unsigned char u8;
typedef unsigned short u16;

extern u8 *D_8009B45C;

void func_80046990(int first, int second, int third)
{
    *(int *)(D_8009B45C + 0x3C) = 0;
    if (first == 0)
        D_8009B45C[0x4A] &= 0xFE;
    if (second == 0)
        D_8009B45C[0x4A] &= 0xFD;
    if (third == 0)
        D_8009B45C[0x4A] &= 0xBF;
    *(u16 *)(D_8009B45C + 0x40) |= 0xA;
}
