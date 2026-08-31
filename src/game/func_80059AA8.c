typedef struct {
    unsigned char pad0[0xE12];
    unsigned char value;
    unsigned char padE13[0xD];
} EntryE20;

extern EntryE20 D_800F2C40[];

int func_80059AA8(int index, int value)
{
    register EntryE20 *entry;
    register int old;

    {
        register EntryE20 *base = D_800F2C40;

        
        entry = (EntryE20 *)(index * sizeof(EntryE20));
        
        entry = (EntryE20 *)((unsigned int)entry + (unsigned int)base);
    }
    
    old = entry->value;
    if (value >= 0) {
        entry->value = value;
    }
    return old;
}
