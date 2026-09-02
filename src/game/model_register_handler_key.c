#include "../types.h"

struct Entry {
    s32 val;    /* 0x0 */
    s32 key;    /* 0x4 */
};

/* Fixed 80-entry linear-probed table. Callers never use the return value. */
extern struct Entry D_800F5918[80];

/* Finds `key` in the table; if absent and there is a free slot, claims it
   with (key, val). No-op once all 80 slots are taken and no match exists. */
void Model_RegisterHandlerKey(s32 key, s32 val) {
    s32 i;
    struct Entry *e = D_800F5918;
    for (i = 0; i < 80; i++, e++) {
        if (e->key == key) {
            return;
        }
        if (e->key != 0) {
            continue;
        }
        if (e->val != 0) {
            continue;
        }
        e->key = key;
        e->val = val;
        return;
    }
}
