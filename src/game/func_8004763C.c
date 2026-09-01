typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

/* Same *D_8009B45C struct as other siblings. Fills the u16 array at f43C
   from index f4 up to (but not including) f0 with 0xFFFF, always sets
   f442=0xFFFF regardless of whether the fill ran, then propagates f4 into
   f440 and recomputes f438 from f448's own f4 field plus 0x1010. The
   final field group is read via a fresh D_8009B45C dereference rather
   than the cached local (see project_d8009b45c_reload_pointer_trick). */
struct Sub {
    char pad[4];
    u32 f4;
};

struct S8009B45C {
    u16 f0;
    char pad0[4 - 2];
    u16 f4;
    char pad1[0x438 - 6];
    u32 f438;
    u16 *f43C;
    u16 f440;
    u16 f442;
    char pad2[0x448 - 0x444];
    struct Sub *f448;
};

extern struct S8009B45C *g_SDValue;

void func_8004763C(void) {
    struct S8009B45C *a1 = g_SDValue;
    s32 i = a1->f4;

    a1->f442 = 0xFFFF;
    if (i < a1->f0) {
        do {
            a1->f43C[i] = 0xFFFF;
            i++;
        } while (i < a1->f0);
    }
    g_SDValue->f440 = g_SDValue->f4;
    g_SDValue->f438 = g_SDValue->f448->f4 + 0x1010;
}
