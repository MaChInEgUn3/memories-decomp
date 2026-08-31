typedef struct {
    unsigned char slots[3][16];
    unsigned char pad30[0xDF0];
} EntryE20;

extern EntryE20 D_800F39B0[];

unsigned char *func_800591C0(unsigned int index, unsigned int slot)
{
    register unsigned char *entry asm("$2");

    if (slot >= 3) {
        slot = 0;
    }
    entry = (unsigned char *)&D_800F39B0[index];
    asm("" : "+r"(entry));
    return entry + slot * 16;
}
