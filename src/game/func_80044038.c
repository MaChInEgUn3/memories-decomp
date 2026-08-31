extern void *D_800F2AF0[];
extern volatile int D_8009B450;
extern void func_80043D48(void **);
extern void func_8008B3A0(int);

void func_80044038(int value)
{
    int count = 10;
    do {
        func_80043D48(D_800F2AF0);
        func_8008B3A0(value);
        while (D_8009B450 < 0) {
        }
        if (D_8009B450 != 1)
            break;
        count--;
    } while (count > 0);
}
