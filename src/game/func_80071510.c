extern int D_800F5B98[];
extern unsigned char D_800EAE90;
extern int func_8007058C(void);

void func_80071510(void)
{
    int index = func_8007058C();
    register int *values asm("$4") = D_800F5B98;
    register unsigned int value asm("$3");

    asm("" : "+r"(values));
    value = D_800EAE90;
    values[index] = value;
}
