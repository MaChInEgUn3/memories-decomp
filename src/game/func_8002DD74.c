typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;


extern u8 D_8009B26C;
extern void (*D_80090B64[])(void);
extern void func_8002CDE8(void), func_80012D4C(void);
extern void func_8002CD8C(void), func_80015B00(void);
void func_8002DD74(void) {
    func_8002CDE8();
    for (;;) {
        u8 v;
        func_80012D4C();
        v = D_8009B26C;
        if ((v & 0x80) == 0) {
            D_8009B26C = v | 0x80;
            func_8002CD8C();
        } else {
            D_80090B64[v & 0x1F]();
            if ((D_8009B26C & 0x40) == 0) func_80015B00();
        }
    }
}
