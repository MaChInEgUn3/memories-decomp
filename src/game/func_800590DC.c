#include "../types.h"
#include "model.h"

extern void func_800540B4(void);
void func_800590DC(int index)
{
    ModelSlot *entry = &D_800F2C40[index];
    unsigned char old = entry->field_E11;
    entry->field_E11 = 1;
    func_800540B4();
    entry->field_E11 = old;
}
