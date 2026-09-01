#include "../types.h"

typedef struct { unsigned char pad[0xE11]; unsigned char value; unsigned char tail[0xE]; } Entry;
extern Entry D_800F2C40[];
extern void func_800540B4(void);
void func_800590DC(int index)
{
    Entry *entry = &D_800F2C40[index];
    unsigned char old = entry->value;
    entry->value = 1;
    func_800540B4();
    entry->value = old;
}
