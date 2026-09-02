#include "../types.h"
#include "model.h"

unsigned int func_80058F74(int index)
{
    ModelSlot *entry = &D_800F2C40[index];

    return (unsigned int)entry->field_D14 + entry->field_E18 * 80;
}
