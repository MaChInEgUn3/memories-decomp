typedef struct {
    unsigned char pad0[0xBF5];
    unsigned char value;
    unsigned char padBF6[0x22A];
} EntryE20;

extern EntryE20 D_800F2C40[];

int func_80058E68(int index)
{
    return D_800F2C40[index].value;
}
