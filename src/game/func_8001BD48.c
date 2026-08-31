extern signed char D_8009B361[];
extern unsigned short D_8009B398[];
extern unsigned char D_8009B164;

int func_8001BD48(void)
{
    if (D_8009B361[0] < 0) {
        if (D_8009B398[0] & 0x100) {
            D_8009B164 = 1;
            return 1;
        }
    }
    return 0;
}
