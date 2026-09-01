#include "../types.h"

typedef struct { unsigned char pad[0xE14]; unsigned char a; unsigned char pad2[10]; unsigned char b; } Entry;
extern Entry D_800F2C40[];
int func_80058DD8(int index)
{
    Entry *entry = &D_800F2C40[index];
    if (entry->a != 0xFF) return 2;
    return entry->b != 0;
}
