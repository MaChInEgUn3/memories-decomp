extern void *D_800F2AE0[];
extern void *D_800F2AF0[];
extern unsigned char D_8009B437;
extern volatile int D_8009B450;
extern int func_800440B4(int, int);
extern void func_80043D48(void **);
extern void func_8008B330(int);
extern void func_8008B3A0(int);
extern void func_8008B340(int);

int func_8004413C(int value)
{
    if (!func_800440B4(value, 2))
        return 0;
    func_80043D48(D_800F2AE0);
    func_8008B330(value);
    while (D_8009B450 < 0) {
    }
    func_80043D48(D_800F2AF0);
    func_8008B3A0(D_8009B437);
    while (D_8009B450 < 0) {
    }
    func_80043D48(D_800F2AE0);
    func_8008B340(value);
    while (D_8009B450 < 0) {
    }
    return 1;
}
