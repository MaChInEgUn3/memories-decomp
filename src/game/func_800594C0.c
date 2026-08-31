typedef struct { int x, y, z, w; } Values;
typedef struct { unsigned char pad[0xDB0]; Values values; unsigned char tail[0x60]; } Entry;
extern Entry D_800F2C40[];
void func_800594C0(int index, Values *source)
{
    Entry *entry = &D_800F2C40[index];
    if (source != 0) {
        entry->values = *source;
    } else {
        entry->values.z = 0x1000;
        entry->values.y = 0x1000;
        entry->values.x = 0x1000;
    }
}
