typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;


extern u8 D_8009B37C;
extern void func_80015B00(void);
extern void func_8003C7A0(void);
s32 func_8003C8CC(void) {
    switch (D_8009B37C & 0xF) {
    case 0: func_80015B00(); break;
    case 1: func_8003C7A0(); break;
    case 2: break;
    case 3: D_8009B37C = 1; break;
    }
    return D_8009B37C;
}
