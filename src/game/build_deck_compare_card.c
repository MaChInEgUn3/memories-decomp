#include "../types.h"

typedef struct { u32 key; s16 index; } Item;
extern s16 gCard_asNameSortKey[];
s32 BuildDeck_CompareCard(Item *arg0, Item *arg1) {
    u32 a = arg0->key;
    u32 b = arg1->key;
    if (a == b) {
        if (gCard_asNameSortKey[arg0->index - 1] < gCard_asNameSortKey[arg1->index - 1])
            return -1;
        return 1;
    }
    if (a < b) return 1;
    return -1;
}
