typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;


typedef struct { s16 value; u8 pad[10]; } Rec12;
extern Rec12 D_801AB000[];
extern s32 D_800F5B98[];
extern s32 func_8007058C(void);
void func_8007149C(void) {
    s32 k = func_8007058C();
    s32 count = 0;
    s32 i;
    for (i = 0xB; i < 0x38; i++)
        if (D_801AB000[i].value != 0) count++;
    D_800F5B98[k] = count - 5;
}
