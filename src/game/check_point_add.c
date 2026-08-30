extern int func_8007058C(void);
extern int D_800F5B98[];

void func_80073624(void)
{
    int left = func_8007058C();
    int right = func_8007058C();
    int output = func_8007058C();
    int *values = D_800F5B98;

    values[output] = values[left] + values[right];
}
