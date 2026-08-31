typedef unsigned char u8;

extern int func_8004BAE4(void *);

int func_8004BB34(u8 *input)
{
    int value = func_8004BAE4(input);
    int result;
    if (value == 0)
        return 0;
    if (value == 255) {
        input[0x24] = 1;
        return 0;
    }
    result = value;
    if (result & 0x80) {
        result &= 0x7F;
        do {
            value = func_8004BAE4(input);
            result = (result << 7) + (value & 0x7F);
        } while (value & 0x80);
    }
    return result;
}
