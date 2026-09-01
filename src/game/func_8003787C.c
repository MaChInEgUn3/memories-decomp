typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

struct Obj {
    u8 pad[81];
    u8 field81;
};

struct Other {
    u8 pad[51];
    u8 field51;
};

extern struct Other *D_8009B328;
extern void func_80039FD4(struct Other *a0);

/* Same field81/bit80 gating as set_field81_bit80_gated.c's func_800378D8,
   but additionally calls func_80039FD4(D_8009B328) before clearing field81
   when D_8009B328->field51 is zero. */
void func_8003787C(struct Obj *a0) {
    u8 v1;
    struct Other *a0b;

    v1 = a0->field81;
    if (!(v1 & 0x80)) {
        a0->field81 = v1 | 0x80;
    }
    a0b = D_8009B328;
    if (a0b->field51 == 0) {
        func_80039FD4(a0b);
        a0->field81 = 0;
    }
}
