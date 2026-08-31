typedef unsigned char u8;

extern u8 *D_8009B45C;
extern void func_80076ED0(int, int);

int func_80047F38(u8 value)
{
    int i;
    int result = 0;
    int mask = 1;
    u8 *state = D_8009B45C;
    for (i = 0; i < 4; i++, mask <<= 1) {
        u8 *item = state;
        item += i;
        if ((item[0x410] & 0xF) == value)
            result |= mask;
    }
    if (result != 0)
        func_80076ED0(0, result << 20);
    return result;
}
