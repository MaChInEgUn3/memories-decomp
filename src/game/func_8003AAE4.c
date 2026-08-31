typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
typedef char M2C_UNK;
typedef struct { s32 words[9]; } Mtx32;
typedef u8 State;
typedef u8 Record;
typedef u8 Pair;
typedef u8 Controller;
typedef u8 Entry;
typedef u8 Rec;
typedef u8 Block;
typedef struct { u32 words[2]; } Blk8;


extern int D_8009B0D8;
extern s32 func_80039F1C();
extern s32 func_80039F90();
extern s32 func_8003A1EC();
extern s32 func_8003A440();
extern s32 func_8003A920();

void func_8003AAE4(u8 *p) {
    u8 *q;
    u8 *e;
    u8 *c;
    s32 a;
    s32 b;
    s32 v;
    s32 m;
    s32 i;

    if (func_80039F1C(p) == 0) {
        *(s16 *)(p + 0x34) = 0x68;
        p[0x32] |= 0x10;
        if (p[0x3C] != 0) {
            *(s16 *)(p + 0x34) = 0xD8;
        }
        func_8003A920(p, *(s16 *)(p + 0x34), *(s16 *)(p + 0x36));
        q = *(u8 **)p;
        a = *(s8 *)(q + 0x16);
        b = q[0x67];
        func_8003A440((u8 **)p, 0x50000000, a);
        e = p + 0xC;
        func_8003A1EC(p, e, b);
        func_8003A440((u8 **)e, 0x60000000, a - 1);
        *(s16 *)(p + 0x40) = 0;
    }

    v = *(u16 *)(p + 0x40) + D_8009B0D8 * 8;
    *(s16 *)(p + 0x40) = v;

    if (*(s16 *)(p + 0x40) >= 0x80) {
        p[0x33] = 0;
        func_8003A440((u8 **)p, 0, *(s8 *)(*(u8 **)p + 0x16));
        func_80039F90(p + 0xC);
        p[0x32] &= 0xEF;
    } else {
        m = *(s16 *)(p + 0x40);
        m |= (m << 8) | (m << 16);
        for (i = 2, c = p + 8; i >= 0; i--, c -= 4) {
            if (*(u8 **)c != 0) {
                *(s32 *)(*(u8 **)c + 0xC) = m;
            }
            if (*(u8 **)(c + 0xC) != 0) {
                *(s32 *)(*(u8 **)(c + 0xC) + 0xC) = m;
            }
        }
    }
}
