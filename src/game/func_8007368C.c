typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;

extern s32 D_800F5B98[];
extern u8 D_800EAE8F[];
extern s32 func_8007058C(void);

void func_8007368C(void)
{
    D_800EAE8F[0] = *(u8 *)&D_800F5B98[func_8007058C()];
}
