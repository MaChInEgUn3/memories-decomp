typedef struct { unsigned char pad[0xD14]; unsigned char *items; unsigned char rest[0xFF]; unsigned char count; unsigned char fallback; unsigned char tail[7]; } Entry;
extern Entry D_800F2C40[];
void *func_80058F20(int index, int slot)
{
    Entry *entry = &D_800F2C40[index];
    if (slot > entry->count) slot = entry->fallback;
    return entry->items + slot * 80;
}
