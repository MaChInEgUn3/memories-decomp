extern int D_8009B074;
extern unsigned char D_8009B078;

int func_8005FB14(void)
{
    int value = 0;

    if (D_8009B078 != 0) {
        value = D_8009B074;
    }
    return value;
}
