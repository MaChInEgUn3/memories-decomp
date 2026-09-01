typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 type;
    u8 pad1[15];
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    int field24;
    int field28;
    int field2C;
} Entry;

extern u8 *g_SDValue;
extern void func_8004503C(int, int, int);
extern void func_80045BE8(Entry *);

void func_80047140(int first, int second, int third, int fourth)
{
    Entry entry;
    func_8004503C(-32, 0, 1);
    *(u16 *)(g_SDValue + 0x40) |= 2;
    entry.type = 32;
    entry.field10 = fourth;
    entry.field14 = second;
    entry.field20 = 0;
    entry.field28 = 0;
    entry.field1C = first;
    entry.field24 = third;
    func_80045BE8(&entry);
}
