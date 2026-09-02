#include "../types.h"
#include "model.h"

void *func_80058F20(int index, int slot)
{
    ModelSlot *entry = &D_800F2C40[index];
    if (slot > entry->field_E17) slot = entry->field_E18;
    return entry->field_D14 + slot * 80;
}
