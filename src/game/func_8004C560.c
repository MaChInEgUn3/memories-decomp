#include "../types.h"

typedef struct {
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
} Entry;

extern int func_8004BBBC(int);
extern int func_8004BC2C(Entry *);

int func_8004C560(Entry *entry)
{
    entry->field0 = func_8004BBBC(entry->field0);
    if (entry->field0 == -1)
        return 1;
    entry->field8 = func_8004BC2C(entry);
    entry->field10 = entry->field0;
    entry->fieldC = entry->field0 + entry->field8;
    return 0;
}
