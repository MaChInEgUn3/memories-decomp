typedef struct {
    unsigned char pad0[0xD14];
    unsigned int value;
    unsigned char padD18[0x100];
    unsigned char index;
    unsigned char padE19[7];
} EntryE20;

extern EntryE20 D_800F2C40[];

unsigned int func_80058F74(int index)
{
    EntryE20 *entry = &D_800F2C40[index];

    return entry->value + entry->index * 80;
}
