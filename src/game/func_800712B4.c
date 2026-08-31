typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;


typedef struct { s16 value; u8 pad[10]; } Rec12;
extern s32 D_800F5B98[];
extern Rec12 D_801AB000[];
extern s32 func_8007058C(void);
void func_800712B4(void) {
    s32 *p = D_800F5B98;
    s32 i = p[func_8007058C()];
    p[func_8007058C()] = D_801AB000[i].value;
}
