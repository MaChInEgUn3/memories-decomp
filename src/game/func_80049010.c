typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

/* Same *D_8009B45C struct as set_8009b45c_1582_1584.c/clear_8009b45c_busy.c.
   If the 0x157E slot is active, notifies func_80049C40() (and clears the
   0x80 flag bit) if that flag was set, resets the slot via
   reset_slot_7E0_if_active(), and marks it inactive. Separately, if the
   0x157A counter has run out, clears it via clear_8009b458_4A4_if_set()
   and resets 0x157A/0x1578. Always zeroes 0x1586/0x1588. */

struct S8009B45C {
    char pad0[0x40];
    u16 f40;
    char pad1[0x1578 - 0x42];
    s16 f1578;
    s16 f157A;
    char pad2[0x157E - 0x157C];
    s16 f157E;
    char pad3[0x1586 - 0x1580];
    s16 f1586;
    s16 f1588;
};

extern struct S8009B45C *g_SDValue;
extern void func_800498F8(s32 a0);
extern void func_80049C40(s16 a0);
extern void func_80049CB0(s16 a0);

void func_80049010(void) {
    if (g_SDValue->f157E != -1) {
        if (g_SDValue->f40 & 0x80) {
            func_80049C40(g_SDValue->f157E);
            g_SDValue->f40 = g_SDValue->f40 & 0xFF7F;
        }
        func_80049CB0(g_SDValue->f157E);
        g_SDValue->f157E = -1;
    }

    if (g_SDValue->f157A == 0) {
        func_800498F8(0);
        g_SDValue->f157A = -1;
        g_SDValue->f1578 = -1;
    }

    g_SDValue->f1588 = 0;
    g_SDValue->f1586 = 0;
}
