extern unsigned char *D_8009B290;
extern unsigned short D_8009B27C;
extern unsigned char D_801A8000[];

void func_8002EE20(void)
{
    unsigned char *source = D_8009B290;
    unsigned int offset;

    D_8009B290 = source + 2;
    offset = source[0] | (source[1] << 8);
    D_8009B27C = 0;
    D_8009B290 = D_801A8000 + offset;
}
