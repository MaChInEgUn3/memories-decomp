extern int D_800E9DB0[4];
extern int D_8009B0B8;

void func_800134B4(void)
{
    int i = 3;
    register int *entry asm("$2") = D_800E9DB0;

    asm("" : "+r"(entry));
    entry += 3;
    do {
        *entry = 0;
        i--;
        entry--;
    } while (i >= 0);
    D_8009B0B8 = 0;
}
