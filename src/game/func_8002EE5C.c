extern unsigned short D_801D0200[];

int func_8002EE5C(void)
{
    unsigned short *entry = D_801D0200;
    int i = 0;

    while (i < 40) {
        if (*entry == 0) {
            return 0;
        }
        i++;
        entry++;
    }
    return 1;
}
