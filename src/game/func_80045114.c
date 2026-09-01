typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

struct Entry {
    u8 f0;
    u8 pad[0x2F];
};
struct S8009B45C {
    u8 pad0[0x4A];
    u8 f4A;
    u8 pad1;
    s16 f4C;
    u8 pad2[0x32];
    struct Entry arr[16];
};
extern struct S8009B45C *g_SDValue;
extern void func_8004503C(s16, s32, s32);
extern void func_80045BE8(u8 *);

void func_80045114(void) {
    struct S8009B45C *p = g_SDValue;
    s32 count;

    if ((p->f4A & 0x80) == 0) {
        return;
    }
    count = p->f4C;
    if (p->arr[count].f0 == 0x11) {
        return;
    }
    if (count > 0) {
        if (p->arr[count - 1].f0 == 0x11) {
            return;
        }
        if (count >= 2) {
            if (p->arr[count - 2].f0 == 0x11) {
                return;
            }
        }
    }
    func_8004503C(-0x20, 0, 1);
    {
        u8 local[0x30];
        local[0] = 0x11;
        func_80045BE8(local);
    }
}
