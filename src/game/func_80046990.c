typedef unsigned char u8;
typedef unsigned short u16;

extern u8 *g_SDValue;

void func_80046990(int first, int second, int third)
{
    *(int *)(g_SDValue + 0x3C) = 0;
    if (first == 0)
        g_SDValue[0x4A] &= 0xFE;
    if (second == 0)
        g_SDValue[0x4A] &= 0xFD;
    if (third == 0)
        g_SDValue[0x4A] &= 0xBF;
    *(u16 *)(g_SDValue + 0x40) |= 0xA;
}
