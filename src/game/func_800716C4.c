extern int D_800F5B98[];
extern unsigned char D_800F5C83;
extern int func_8007058C(void);

void func_800716C4(void)
{
    int index = func_8007058C();
    register int *values asm("$4") = D_800F5B98;
    register unsigned int value asm("$3");

    asm("" : "+r"(values));
    value = D_800F5C83;
    values[index] = value;
}
