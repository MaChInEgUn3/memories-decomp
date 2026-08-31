extern void *D_800F2AE0[];
extern short D_8009B44C;
extern int D_8009B430;
extern int func_800440B4(int, int);
extern void func_80043D48(void **);
extern void func_8008B330(int);

int func_80044278(int value, int data, int small)
{
    int result;
    if (func_800440B4(value, 11)) {
        D_8009B44C = small;
        D_8009B430 = data;
        func_80043D48(D_800F2AE0);
        func_8008B330(value);
        result = 1;
    } else {
        result = 0;
    }
    return result;
}
