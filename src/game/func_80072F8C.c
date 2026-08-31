typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

extern s32 D_800F5B98[];
extern s32 func_8007058C(void);
extern u8 D_800EAE88[];

void func_80072F8C(void) {
    s32 *t = D_800F5B98;
    s32 a = t[func_8007058C()];
    s32 b = t[func_8007058C()];
    s32 c = t[func_8007058C()];
    s32 d = t[func_8007058C()];
    s32 e = t[func_8007058C()];

    D_800EAE88[5] = 0;
    D_800EAE88[0] = a;
    D_800EAE88[1] = b;
    D_800EAE88[2] = c;
    D_800EAE88[3] = d;
    D_800EAE88[4] = e;
}
