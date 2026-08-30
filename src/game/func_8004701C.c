extern unsigned char *D_8009B45C;
void func_8004701C(int value)
{
    D_8009B45C[0x4A] = (D_8009B45C[0x4A] & 0xF0) | value;
}
