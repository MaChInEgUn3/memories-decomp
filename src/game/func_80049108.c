extern unsigned char *D_8009B45C;
void func_80049108(short value, unsigned char flag)
{
    *(short *)(D_8009B45C + 0x1582) = value;
    D_8009B45C[0x1584] = flag;
}
