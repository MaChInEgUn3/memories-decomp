extern int func_8007058C(void);
extern int D_800F5B98[];

void func_800735DC(void)
{
    int source = func_8007058C();
    int destination = func_8007058C();
    register volatile int *values asm("$3") = D_800F5B98;
    register int value asm("$4");
    volatile int *destination_value = &values[destination];

    value = values[source];
    *destination_value = value;
}
