#include "../types.h"

/* Same stride-28 table as DuelEffect_ClearMatchingMarker/clear_two_fields_800eb288 (see
   clear_matching_byte_800eb288.c): field17 gates the scan, field19 is the
   match test. */
struct Obj {
    u8 pad[92];
    u16 field92;
    u16 field94;
};

extern u8 D_800EB288[];

/* Starting from record a0->field92, scans up to a0->field94 stride-28
   entries; returns 1 on the first entry with field17&0x80 set and field19
   nonzero, 0 if field17's bit clears, the count runs out, or field94==0. */
int DuelEffect_HasActiveEntry(struct Obj *a0) {
    int v0;
    int count;
    u8 *v1;
    v0 = a0->field92;
    count = a0->field94;
    v1 = D_800EB288 + v0 * 28;
    if (count == 0) {
        goto ret_zero_a;
    }
    v1 = v1 + 19;
loop:
    v0 = v1[-2] & 0x80;
    if (v0 == 0) {
        return v0;
    }
    if (v1[0] != 0) {
        return 1;
    }
    count = count - 1;
    v1 = v1 + 28;
    if (count != 0) {
        goto loop;
    }
ret_zero_a:
    return 0;
}
