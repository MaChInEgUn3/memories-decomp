extern unsigned short D_801D0200[];

int func_8002C4DC(int value)
{
    unsigned short *entry = D_801D0200;
    int i = 0;

    while (i < 40) {
        if (*entry == value) {
            return i;
        }
        i++;
        entry++;
    }
    return -1;
}
