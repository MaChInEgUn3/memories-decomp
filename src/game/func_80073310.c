typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;


extern s32 D_800F5B98[];
extern u8 gAiScript_State[];
extern s32 func_8007058C(void);
void func_80073310(void) {
    s32 *p = D_800F5B98;
    u8 *q;
    s32 v;
    s32 i;
    v = p[func_8007058C()];
    q = gAiScript_State;
    for (i = 0; i < 0x20; i++) {
        u16 c = *(u16 *)(q + i * 2 + 0x3E);
        if (c == v) return;
        if (c == 0) { *(u16 *)(q + i * 2 + 0x3E) = v; return; }
    }
}
