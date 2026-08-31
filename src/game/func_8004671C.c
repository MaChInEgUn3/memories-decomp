typedef struct {
    int field0;
    short field4;
    short field6;
    char pad8[8];
    short field10;
    short field12;
    int field14;
    int field18;
    int pad1C[3];
} Entry;

extern void func_80077C70(Entry *);

void func_8004671C(void)
{
    Entry entry;
    entry.field0 = 707;
    entry.field4 = 16383;
    entry.field6 = 16383;
    entry.field10 = 32767;
    entry.field12 = 32767;
    entry.field14 = 0;
    entry.field18 = 1;
    func_80077C70(&entry);
}
