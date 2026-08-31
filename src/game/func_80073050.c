typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;

extern s32 D_800F5B98[];
extern u8 D_800EAE8E[];
extern s32 func_8007058C(void);

void func_80073050(void)
{
    s32 *p = D_800F5B98;
    s32 v;

    v = p[func_8007058C()];
    D_800EAE8E[0] = v;
}
