typedef struct {
    unsigned char pad0[0xE12];
    unsigned char value;
    unsigned char padE13[0xD];
} EntryE20;

extern EntryE20 D_800F2C40[];

int func_80059AA8(int index, int value)
{
    register EntryE20 *entry asm("$2");
    register int old asm("$3");

    {
        register EntryE20 *base asm("$3") = D_800F2C40;

        asm("" : "+r"(base));
        entry = (EntryE20 *)(index * sizeof(EntryE20));
        asm("" : "+r"(entry));
        entry = (EntryE20 *)((unsigned int)entry + (unsigned int)base);
    }
    asm("" : "+r"(entry));
    old = entry->value;
    if (value >= 0) {
        entry->value = value;
    }
    return old;
}
