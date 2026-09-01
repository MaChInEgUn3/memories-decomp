typedef unsigned char u8;
typedef unsigned short u16;

extern u8 *g_SDValue;
extern int func_800496C4(void *, int, int);

void func_80049308(void)
{
    u8 *state = g_SDValue;
    if (*(short *)(state + 0x157A) != 0) {
        u8 *entry = *(u8 **)(state + 0x1564);
        int result = func_800496C4(entry + 0x50, 0, *(int *)(entry + 0x0C));
        *(short *)(g_SDValue + 0x157A) = result;
        if ((result << 16) != 0) {
            *(short *)(g_SDValue + 0x1578) = -1;
            *(short *)(g_SDValue + 0x157A) = -1;
            return;
        }
    }
    {
        register u8 *final = g_SDValue;
        register u16 *entry = *(u16 **)(final + 0x1564);
        *(u16 *)(final + 0x1578) = *entry;
    }
}
