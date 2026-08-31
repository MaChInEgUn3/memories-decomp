typedef struct {
    unsigned char pad0[8];
    unsigned short flags;
    unsigned char padA[0x66];
} Entry;

extern Entry D_800EFE48[];

int func_8004006C(void)
{
    Entry *entry = D_800EFE48;
    int i;

    for (i = 0; i < 0x60; i++, entry++) {
        if ((entry->flags & 0x80) == 0) {
            return i;
        }
    }
    return -1;
}
