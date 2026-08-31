typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

typedef void (*Handler)(void);
struct Big {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    u8 pad2[4];
    u8 count;
    u8 pad3[3];
    s32 items[1];
};
extern s32 func_8007058C(void);
extern s32 func_80074170(s32);
extern Handler D_800916E0[];
extern void func_80070FF8(void);
extern void func_80071000(void);
extern void func_80070F1C(void);
extern struct Big D_800F5BE8;

s32 func_80070650(void) {
    for (;;) {
        s32 idx;
        Handler h;

        D_800F5BE8.fC = D_800F5BE8.f8;
        idx = func_8007058C();
        D_800916E0[idx]();
        h = D_800916E0[idx];

        if (h == func_80070FF8) {
            return 1;
        }
        if (h == func_80071000) {
            return 3;
        }
        if (h == func_80070F1C) {
            return 2;
        }

        if (func_80074170(1) >= 0xF0) {
            break;
        }
    }

    return 0;
}
