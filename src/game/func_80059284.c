typedef struct {
    unsigned char pad0[0xE11];
    unsigned char value;
    unsigned char padE12[0xE];
} EntryE20;

extern EntryE20 D_800F2C40[];

void func_80059284(int index, int value)
{
    D_800F2C40[index].value = value;
}
