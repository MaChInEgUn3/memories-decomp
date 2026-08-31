extern unsigned short D_8009B27C;

int func_8002E3B4(void)
{
    unsigned short value = D_8009B27C;

    if (!(value & 0x8000)) {
        D_8009B27C = value | 0x8000;
        return 0;
    }
    return 1;
}
