typedef struct {
    short field0;
    unsigned char pad2[2];
    unsigned char field4;
    unsigned char pad5[0x1B];
} Entry;

typedef struct {
    unsigned char bytes[0x118];
} Pool;

extern unsigned char D_8009B260;
extern Pool D_800EAD88;

void func_8002C598(void)
{
    Entry *entry;
    Pool *pool;
    int count;
    int fill;

    D_8009B260 = 0;
    count = 8;
    fill = -1;
    pool = &D_800EAD88;
    entry = (Entry *)((unsigned char *)pool + 0x18);
    do {
        entry->field4 = 0;
        entry->field0 = fill;
        entry++;
    } while (--count != 0);
}
