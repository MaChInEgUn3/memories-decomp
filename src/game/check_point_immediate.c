extern int func_8007058C(void);
extern int func_800705AC(void);
extern int D_800F5B98[];

void func_800735A0(void)
{
    int value = func_800705AC();
    int index = func_8007058C();
    volatile int *values = D_800F5B98;

    values[index] = value;
}
