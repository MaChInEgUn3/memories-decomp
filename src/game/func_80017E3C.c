typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

/* Same D_801A7AD8[] stat table (0x1C-byte stride) as
   table801a7ad8_row_search.c / func_8001EFD4.c. Applies the record at
   D_801A7AD8[a0->f6A]'s flags to a0: clears f67 unless bit 0x2000 is set,
   clears a0->f8's bit 0x4, and if either of bits 0x1000/0x0800 is set,
   re-marks f8 with bit 0x4, resets f21/f22 and re-derives them from those
   two bits (0x80 / 0xC0). Always sets fC to 0x808080, or 0x404040 if bit
   0x4000 is set. */
struct Table801A7AD8 {
    char pad0[0x16];
    u16 flags;                 /* 0x16 */
    char pad1[0x1C - 0x18];
};

struct Obj {
    char pad0[0x8];
    u16 f8;
    char pad1[0xC - 0xA];
    u32 fC;
    char pad2[0x21 - 0x10];
    u8 f21;
    u8 f22;
    char pad3[0x67 - 0x23];
    u8 f67;
    char pad4[0x6A - 0x68];
    u8 f6A;
};

extern struct Table801A7AD8 D_801A7AD8[];

void func_80017E3C(struct Obj *a0) {
    struct Table801A7AD8 *rec = &D_801A7AD8[a0->f6A];
    u16 flags8;

    if (!(rec->flags & 0x2000)) {
        a0->f67 = 0;
    }
    flags8 = a0->f8 & 0xFFFB;
    a0->f8 = flags8;
    if (rec->flags & 0x1800) {
        a0->f8 = flags8 | 4;
        a0->f21 = 0;
        if (rec->flags & 0x1000) {
            a0->f21 = 0x80;
        }
        a0->f22 = 0;
        if (rec->flags & 0x800) {
            a0->f22 = 0xC0;
        }
    }
    a0->fC = 0x808080;
    if (rec->flags & 0x4000) {
        a0->fC = 0x404040;
    }
}
