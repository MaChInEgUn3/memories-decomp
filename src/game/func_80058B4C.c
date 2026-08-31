typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
typedef struct LocalWords7 { s32 w[7]; } LocalWords7;
extern int func_80058A7C();
extern int func_800598E4();
extern int func_80081DE8();
extern int func_80082324();
extern int func_80086100();

s32 func_80058B4C(u8 *p, s32 arg1, s32 mode, s32 arg3, s32 x, s32 y, s32 z,
                  s32 w) {
    u16 b[4];
    s32 hi;
    s32 lo;

    hi = 0;
    lo = hi;

    if (func_800598E4(arg1, 0x80400000) > 0) {
        func_80086100(0x80400004, p);
        if (mode < 2) {
            if (*(s32 *)(p + 4) == 0) {
                *(s16 *)(p + 4) = 0xC0;
                *(s16 *)(p + 6) = 0x100;
            }
            if (*(s32 *)(p + 0x10) == 0) {
                *(s16 *)(p + 0x10) = 0x200;
                *(s16 *)(p + 0x12) = 0xF2;
            }
            if (x >= 0) {
                *(s16 *)(p + 4) = x;
            } else {
                *(u16 *)(p + 4) = *(u16 *)(p + 4) + ((mode & 1) << 8);
            }
            if (y >= 0) {
                *(s16 *)(p + 6) = y;
            }
            if (z >= 0) {
                *(s16 *)(p + 0x10) = z;
            }
            if (w >= 0) {
                *(s16 *)(p + 0x12) = w;
            } else {
                *(u16 *)(p + 0x12) = *(u16 *)(p + 0x12) + mode;
            }
        } else if (mode >= 3) {
            func_80058A7C(mode - 3, arg3, (LocalWords7 *)p);
        }

        b[0] = *(u16 *)(p + 4);
        b[1] = *(u16 *)(p + 6);
        b[2] = *(u16 *)(p + 8);
        b[3] = *(u16 *)(p + 0xA);
        while (func_80082324(3) != 0) {
        }
        while (func_80081DE8(b, *(s32 *)(p + 0xC)) != 0) {
        }
        b[0] = *(u16 *)(p + 0x10);
        b[1] = *(u16 *)(p + 0x12);
        b[2] = *(u16 *)(p + 0x14);
        b[3] = *(u16 *)(p + 0x16);
        while (func_80082324(3) != 0) {
        }
        while (func_80081DE8(b, *(s32 *)(p + 0x18)) != 0) {
        }
        while (func_80082324(3) != 0) {
        }
        hi = ((*(u16 *)p & 3) << 7) | ((arg3 & 3) << 5) |
             (((s32)(*(u16 *)(p + 6) & 0x100) << 16) >> 20) |
             ((*(u16 *)(p + 4) & 0x3FF) >> 6) |
             ((*(u16 *)(p + 6) & 0x200) << 2);
        lo = (*(u16 *)(p + 0x12) << 6) | ((*(u16 *)(p + 0x10) >> 4) & 0x3F);
    }

    return (hi << 16) | (lo & 0xFFFF);
}
