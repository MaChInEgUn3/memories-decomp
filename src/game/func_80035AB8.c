#include "../types.h"
#include "duel_effect.h"

void func_80035AB8(int index, int first, int second, int third, int fourth)
{
    DuelEffectChannel *entry = &D_800EB0F8[index];
    entry->field_3C = first;
    entry->field_40 = second;
    entry->field_3E = third;
    entry->field_42 = fourth;
}
