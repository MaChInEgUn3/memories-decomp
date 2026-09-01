typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

/* Same D_800907D8/D_801A7AD8 scan as func_8002778C.c, but skips the
   func_8001EFD4 comparison (while still counting the row as "found") when
   the row's own 0x1000 flag bit is set. Scans D_800907D8's current-row
   entries [5..9] (20-byte stride selected by D_8009B1D5), each a
   D_801A7AD8 table index. For rows whose entry has the 0x8000 flag set,
   compares *arg0 against the entry's own object via func_8001EFD4 (unless
   0x1000 is also set) and returns the winning entry's f6A byte as soon as
   one scores > 0. If no row ever had 0x8000 set, falls back to row [7]'s
   value; otherwise (some were tested, none won) returns -1. */
struct Obj {
    char pad[0x6A];
    u8 f6A;
};

struct Table801A7AD8 {
    struct Obj *f0;
    char pad1[0x16 - 0x4];
    u16 f16;
    char pad2[0x1C - 0x18];
};

extern s32 func_8001EFD4(struct Obj *a0, struct Obj *a1);
extern u8 D_800907D8[];
extern struct Table801A7AD8 D_801A7AD8[];
extern u8 D_8009B1D5;

s32 func_800278A0(void *arg0) {
    s32 i;
    s32 found = 0;
    struct Table801A7AD8 *entry = 0;

    for (i = 5; i < 10; i++) {
        u8 row = D_800907D8[i + D_8009B1D5 * 20];
        entry = &D_801A7AD8[row];
        if (entry->f16 & 0x8000) {
            found++;
            if (!(entry->f16 & 0x1000)) {
                s32 result = func_8001EFD4(*(struct Obj **)arg0, entry->f0);
                if (result > 0) {
                    return entry->f0->f6A;
                }
            }
        }
    }

    if (found == 0) {
        return D_800907D8[D_8009B1D5 * 20 + 7];
    }
    return -1;
}
