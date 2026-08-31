extern int D_800F5B98[];
extern unsigned char D_8009B364;
extern int func_8007058C(void);

void func_80071460(void)
{
    int index = func_8007058C();
    register int *values asm("$3") = D_800F5B98;
    register unsigned int value asm("$4");

    asm("" : "+r"(values));
    value = D_8009B364;
    values[index] = value;
}
