typedef unsigned char u8;
typedef unsigned short u16;

extern u8 *g_SDValue;
extern int func_80047C50(int);
extern void func_80047C70(int);

void func_80047CC4(int value)
{
    int normalized = func_80047C50((u16)value);
    u8 *state = g_SDValue;
    int tries = 0;
    int slot = state[0x435];
    int bit = 1 << (u8)slot;
    int command = 1 << ((u8)slot + 20);
    do {
        state = g_SDValue;
        if (state[0x434] & bit) {
            u8 *item = state;
            item += (u8)slot * 2;
            if (*(u16 *)(item + 0x404) == (u16)normalized) {
                func_80047C70(command);
                g_SDValue[0x435] = slot;
                g_SDValue[0x434] &= ~bit;
                break;
            }
        }
        bit <<= 1;
        command <<= 1;
        if (bit & 0x10)
            bit = 1;
        slot++;
        tries++;
        slot &= 3;
    } while (tries < 4);
}
