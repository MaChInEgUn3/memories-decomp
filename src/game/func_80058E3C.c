typedef struct {
    unsigned char pad0[0xE0D];
    unsigned char value;
    unsigned char padE0E[0x12];
} EntryE20;

extern EntryE20 D_800F2C40[];

int func_80058E3C(int index)
{
    return D_800F2C40[index].value;
}
