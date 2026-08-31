extern int D_800F5B98[];
extern unsigned short D_800F5C80;
extern int func_8007058C(void);

void func_8007164C(void)
{
    int index = func_8007058C();
    register int *values asm("$4") = D_800F5B98;
    register unsigned int value asm("$3");

    asm("" : "+r"(values));
    value = D_800F5C80;
    values[index] = value;
}
