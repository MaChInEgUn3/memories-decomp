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



extern s32 (*func_800603DC())();
extern s32 func_8007F6CC();
extern s32 func_80089E20();

void func_80060220(s32 arg0, u8 *arg1, u8 *arg2) {
    u8 *p;
    u8 *q;
    u8 *b;
    u16 *e;
    u8 *r;
    u8 *rec;
    s32 n;
    s32 i;
    s32 j;
    s32 k;
    s32 f;
    s32 sh;
    s32 v;
    s32 w;
    s32 m;

    m = 0x2000001;
    i = 0;
    q = *(u8 **)arg2;
    r = arg2;
    n = *(u16 *)(q + 2);
    q += 4;

    if (n != 0) {
        f = arg0 < 2;
        sh = arg0 << 8;
        p = q;


        do {
            q = p + 0xC;
            if (*(s32 *)arg1 == m) {
                b = *(u8 **)(r + 0x18);
                if (b != (u8 *)0) {
                    j = 0;
                    e = (u16 *)(b + *(s32 *)(q + 8) * 4);
                    rec = q;
                    if (*(s16 *)(q + 6) > 0) {
                        do {
                            if (f) {
                                *e = 0;
                            }
                            e++;
                            for (k = 1; k < *(s16 *)(rec + 4); k++) {
                                *e |= 0x8000;
                                e++;
                            }
                            j++;
                        } while (j < *(s16 *)(rec + 6));
                    }
                    if (f) {
                        v = *(u16 *)rec;
                        if (*(s16 *)rec >= 0x280) {
                            *(u16 *)rec = (v - 0x280) + sh;
                        } else {
                            *(u16 *)rec = sh;
                        }
                        v = *(s16 *)(rec + 2);
                        if (v >= 8) {
                            *(s16 *)(rec + 2) = v % 8;
                        }
                        *(u16 *)(rec + 2) = *(u16 *)(rec + 2) + 0xF8;
                    }
                    q += 0xC;
                }
            }
            if (f) {
                w = *(u16 *)p;
                *(u16 *)p = (w - 0x280) + sh;
            }
            i++;
            p = q;

        } while (i < n);
    }

    func_800603DC(*(s32 *)arg1)(arg2);
    func_8007F6CC(0);
    *(u8 *(**)(u8 **))(*(s32 *)(arg1 + 4)) = func_80089E20;
}
