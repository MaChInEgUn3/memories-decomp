extern unsigned char *D_8009B45C;
void func_8004503C(short value, unsigned char flag)
{
    *(short *)(D_8009B45C + 0x512) = value;
    D_8009B45C[0x49] = flag;
}
