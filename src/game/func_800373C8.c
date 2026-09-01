#include "../types.h"

/* Same stride-28 table as scan_flag80_entries_800eb288/func_80035DB8/
   clear_two_fields_800eb288 (see clear_matching_byte_800eb288.c): field17
   gates the scan, field19/field21 are the two bytes written here. */
struct Obj {
    u8 pad[92];
    u16 field92;
    u16 field94;
};

extern u8 D_800EB288[];

/* Starting from record a0->field92, walks up to a0->field94 stride-28
   entries; for each with field17&0x80 set, writes a1 to field19 and a2 to
   field21, stopping at the first entry with field17's bit clear or when the
   count runs out. */
void func_800373C8(struct Obj *a0, u8 a1, u8 a2) {
    int v0;
    int count;
    u8 *v1;

    v0 = a0->field92;
    count = a0->field94;
    v1 = D_800EB288 + v0 * 28;
    if (count == 0) {
        return;
    }
    v1 = v1 + 21;
loop:
    if ((v1[-4] & 0x80) == 0) {
        return;
    }
    count = count - 1;
    v1[-2] = a1;
    v1[0] = a2;
    v1 = v1 + 28;
    if (count != 0) {
        goto loop;
    }
}
