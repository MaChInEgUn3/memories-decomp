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

extern u8 *D_8009B45C;
extern void func_8004503C(int, int, int);
extern void func_80045BE8(Entry *);

void func_800470B0(int first, int second, int third, int fourth)
{
    Entry entry;
    func_8004503C(-32, 0, 1);
    *(u16 *)(D_8009B45C + 0x40) |= 2;
    entry.type = 32;
    entry.field10 = fourth;
    entry.field14 = second;
    entry.field20 = first;
    entry.field28 = third;
    entry.field1C = 0;
    entry.field24 = 0;
    func_80045BE8(&entry);
}
