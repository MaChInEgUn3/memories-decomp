#include "../types.h"
#include "sound.h"

/* Same *D_8009B458 struct as set_8009b458_510_validated.c (f510 = item
   count, 1..20). Walks the 0x28-byte item array starting at offset 0x180
   and, for each item whose durability (f1E) is non-zero and whose type
   byte (f3) is below 0x10, decrements the durability by 1; otherwise
   resets it to 0. */
void func_8004C84C(void) {
    s32 i;

    for (i = 0; i < D_8009B458->object_count; i++) {
        SDSecondaryObject *item = &D_8009B458->objects[i];
        if (item->field_001E != 0 && item->field_0003 < 0x10) {
            item->field_001E -= 1;
        } else {
            item->field_001E = 0;
        }
    }
}
