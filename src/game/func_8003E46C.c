extern unsigned char D_8009B3C6;
extern volatile unsigned short D_8009B3FA;

void func_8003E46C(unsigned char value, unsigned short bits)
{
    unsigned short flags = D_8009B3FA;

    bits |= 0x80;
    D_8009B3C6 = value;
    flags &= 0xFF87;
    D_8009B3FA = flags;
    D_8009B3FA = flags | bits;
}
