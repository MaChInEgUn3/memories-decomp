extern unsigned char *D_8009B458;

void func_800498F8(void)
{
    short *value = (short *)(D_8009B458 + 0x4A4);

    if (*value != -1) {
        *value = -1;
    }
}
