typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

typedef struct Rec12 {
    s16 unk0;
    u8 pad2[6];
    s8 unk8;
    u8 pad9[3];
} Rec12;
extern s32 D_800F5B98[];
extern s32 func_8007058C(void);
extern u8 D_800EAE88[];
extern Rec12 D_801AB000[];

void func_800726F4(void) {
    s32 *t = D_800F5B98;
    s32 c = t[func_8007058C()];
    s32 n = func_8007058C();
    s32 i = 0;
    u8 *b = D_800EAE88;
    Rec12 *tb = D_801AB000;

    do {
        s32 k = *(u8 *)(i + (s32)b);
        Rec12 *r = (Rec12 *)(k * 12 + (s32)tb);

        if (r->unk0 != 0 && r->unk8 == c) {
            t[n] = k;

            return;
        }
        i++;
    } while (i < 5);

    D_800F5B98[n] = 0;
}
