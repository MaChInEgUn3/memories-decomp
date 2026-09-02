#include "../types.h"
#include "model.h"

void func_80059590(
    int index,
    int fourth,
    int first,
    int second,
    int third)
{
    ModelSlot *entry = &D_800F2C40[index];

    entry->field_DC0[3] = fourth;
    entry->field_DC0[0] = first;
    entry->field_DC0[1] = second;
    entry->field_DC0[2] = third;
}
