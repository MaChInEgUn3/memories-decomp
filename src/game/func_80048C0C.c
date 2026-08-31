typedef unsigned char u8;
typedef unsigned short u16;

extern u8 *D_8009B45C;

void func_80048C0C(u16 value, u8 enabled)
{
    int i;
    int mask;
    if (enabled == 0)
        return;
    mask = 1;
    for (i = 0; i < 4; i++, mask <<= 1) {
        u8 *state = D_8009B45C;
        u8 *item = state;
        item += i * 2;
        if (*(u16 *)(item + 0x404) == value &&
            (state[0x434] & mask)) {
            item = state;
            item += i;
            item[0x428] = enabled;
        }
    }
}
