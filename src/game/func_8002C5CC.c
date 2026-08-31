typedef struct {
    unsigned char pad0[0x1C];
    unsigned char flags;
    unsigned char pad1D[3];
} Entry;

extern Entry D_800EAD88[];

Entry *func_8002C5CC(void)
{
    Entry *entry = D_800EAD88;
    int count = 8;

    for (;;) {
        if (!(entry->flags & 0x80)) {
            return entry;
        }
        if (--count == 0) {
            return 0;
        }
        entry++;
    }
}
