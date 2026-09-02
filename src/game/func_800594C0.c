#include "../types.h"
#include "model.h"

typedef ModelSlotS32Quad Values;
void func_800594C0(int index, Values *source)
{
    ModelSlot *entry = &D_800F2C40[index];
    if (source != 0) {
        entry->field_DB0 = *source;
    } else {
        entry->field_DB0.field_08 = 0x1000;
        entry->field_DB0.field_04 = 0x1000;
        entry->field_DB0.field_00 = 0x1000;
    }
}
