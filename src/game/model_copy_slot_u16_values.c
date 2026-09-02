#include "../types.h"

/* Same D_800F2C40 record table as get_D_800F2C40_slot_field.c; copies the
   4-entry u16 array at 0xDD0 of record[idx] out to caller-supplied storage. */
struct RecD800F2C40 {
    char pad[0xDD0];
    u16 arr[4]; /* 0xDD0 */
    char pad2[0xE20 - 0xDD8];
};

extern struct RecD800F2C40 D_800F2C40[];

void Model_CopySlotU16Values(s32 idx, u16 *out) {
    struct RecD800F2C40 *rec = &D_800F2C40[idx];
    out[0] = rec->arr[0];
    out[1] = rec->arr[1];
    out[2] = rec->arr[2];
    out[3] = rec->arr[3];
}
