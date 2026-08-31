typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;


typedef struct { u8 pad[25]; s8 value; u8 tail[6]; } Rec32;
extern s32 D_800F5B98[];
extern Rec32 D_800E9FF0[];
extern u8 D_8009B1D5[];
extern s32 func_8007058C(void);
void func_8007154C(void) {
    s32 *p = D_800F5B98;
    s32 i = p[func_8007058C()];
    p[func_8007058C()] = D_800E9FF0[(D_8009B1D5[0] ^ 1) ^ i].value != 0;
}
