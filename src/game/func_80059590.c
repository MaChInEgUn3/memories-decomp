typedef struct {
    unsigned char pad0[0xDC0];
    unsigned char first;
    unsigned char second;
    unsigned char third;
    unsigned char fourth;
    unsigned char padDC4[0x5C];
} EntryE20;

extern EntryE20 D_800F2C40[];

void func_80059590(
    int index,
    int fourth,
    int first,
    int second,
    int third)
{
    EntryE20 *entry = &D_800F2C40[index];

    entry->fourth = fourth;
    entry->first = first;
    entry->second = second;
    entry->third = third;
}
