typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;


extern s32 D_800F5B98[];
extern s32 func_8007058C(void);
extern s32 func_8002C7E8(s32, s32);
void func_800725C4(void) {
    s32 *p = D_800F5B98;
    s32 v = p[func_8007058C()];
    s32 k = func_8007058C();
    if (func_8002C7E8(0, v) != 0) p[k] = 1;
    else p[k] = 0;
}
