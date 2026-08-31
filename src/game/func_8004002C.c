typedef struct {
    unsigned char pad0[8];
    unsigned short flags;
    unsigned char padA[0x66];
} Entry;

extern Entry D_800F0548[];

int func_8004002C(void)
{
    Entry *entry = D_800F0548;
    int i;

    for (i = 16; i < 0x60; i++, entry++) {
        if ((entry->flags & 0x80) == 0) {
            return i;
        }
    }
    return -1;
}
