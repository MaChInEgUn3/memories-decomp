typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;


extern s32 D_800F5B98[];
extern s32 D_801D4244[];
extern s32 func_8007058C(void);
void func_80071248(void) {
    s32 *p = D_800F5B98;
    s32 i = p[func_8007058C()] - 1;
    p[func_8007058C()] = (D_801D4244[i] >> 26) & 0x1F;
}
