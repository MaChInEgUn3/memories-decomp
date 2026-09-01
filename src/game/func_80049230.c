typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 type;
    u8 pad1;
    short value;
    int pad4;
    int data;
    u8 padC[0x24];
} Entry;

extern u8 *g_SDValue;
extern void func_80049010(void);
extern void func_80049138(short, int);
extern void func_80045BE8(Entry *);

void func_80049230(int value, int data)
{
    Entry entry;
    short small = value;
    if (small < 0) {
        func_80049010();
        return;
    }
    if (**(u16 **)(g_SDValue + 0x1564) != (small >> 4))
        func_80049138(small, 1);
    entry.type = 0x48;
    entry.value = value;
    entry.data = (short)data;
    func_80045BE8(&entry);
    *(short *)(g_SDValue + 0x1582) = data;
    g_SDValue[0x1584] = 255;
}
