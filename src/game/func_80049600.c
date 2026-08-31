typedef unsigned char u8;

extern u8 *D_8009B458;

int func_80049600(int value)
{
    register int original asm("$3") = value;
    register int check asm("$4") = (u8)original;
    register int result asm("$2");
    if ((unsigned int)check >= 21) {
        result = 255;
        return result;
    }
    result = check;
    if (check == 0) {
        result = 255;
        return result;
    }
    *(short *)(D_8009B458 + 0x510) = (u8)original;
    return result;
}
