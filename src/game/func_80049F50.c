typedef unsigned char u8;

extern u8 *D_8009B458;
extern int func_8004CABC(void);

int func_80049F50(void)
{
    int value;
    if (*(short *)(D_8009B458 + 0x7E2) == 1) {
        value = (short)func_8004CABC();
        if (value == 3)
            *(short *)(D_8009B458 + 0x7E2) = value;
    }
    return *(short *)(D_8009B458 + 0x7E2);
}
