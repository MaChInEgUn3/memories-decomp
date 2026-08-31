typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;


extern u8 D_8009B2EB;
extern u8 D_8009B3ED[], D_8009B3EA[], D_8009B26C[];
extern s32 func_8003FD14(void);
extern void func_8005B85C(void);
extern void func_800137E4(void);
void func_80031000(void) {
    u8 v = D_8009B2EB;
    s32 r;
    if ((v & 0x80) == 0) {
        D_8009B2EB = v | 0x80;
        D_8009B3ED[0] = 0;
        D_8009B3EA[0] = 0;
    }
    r = func_8003FD14();
    if (r != 0) {
        if (r == 1) {
            func_8005B85C();
            func_800137E4();
            D_8009B26C[0] = 0x10;
        }
        D_8009B2EB = 0;
    }
}
