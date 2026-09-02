#include "../types.h"
#include "model.h"
extern s32 func_8005FC1C(s32);
extern void func_8005A53C();

void func_80059DD8(s32 index)
{
    ModelSlot *base = &D_800F2C40[index];
    ModelSlotHeadEntry *slot = base->field_000;
    s32 (*callback)(s32) = func_8005FC1C;
    u8 *node;
    u8 *next;
    s32 i;

    if (base->field_E1F == 0)
        return;
    for (i = 0; i < base->field_E1A; i++, slot++) {
        node = slot->field_04;
        if (node != (u8 *)0) {
            while (1) {
                if (*(s32 *)(node + 8) != 0)
                    func_8005A53C(callback, node + 12,
                                  *(s32 *)(node + 4), *(s32 *)(node + 8));
                next = *(u8 **)node;
                if (next == (u8 *)-1)
                    break;
                node = next;
            }
        }
    }
}
