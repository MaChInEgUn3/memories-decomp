extern volatile int D_8009B0F4;
extern int D_8009B134;
extern void func_80015010(void);

void func_80014FA4(void)
{
    int value;

    if ((D_8009B0F4 & 0x2000030) | D_8009B134) {
        value = 0x80;
        if ((D_8009B0F4 & 0x10) && (D_8009B0F4 & 0x80000)) {
            func_80015010();
        }
        D_8009B134 = value;
    }
}
