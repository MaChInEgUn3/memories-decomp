typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 D_801AF000[];
extern void *func_8004002C(void);
extern u8 *func_800400AC(void *, int);
extern void func_800428A8(void *, int, int, int, int, int, int, int, int);
extern void func_800428EC(void *, int);
extern void func_80012D4C(void);
extern void func_8004036C(void *);

void func_8004365C(u8 *optional, u8 *primary)
{
    register u8 *saved_optional asm("$20") = optional;
    register u8 *saved_primary asm("$18") = primary;
    register u8 *optional_child asm("$19");
    register u8 *primary_child asm("$17");
    register int i asm("$16");
    register int top asm("$21");
    asm("" : "+r"(saved_optional));
    asm("" : "+r"(saved_primary));
    optional_child = 0;
    if (saved_optional != 0) {
        optional_child = func_800400AC(func_8004002C(), 2);
        func_800428A8(optional_child, 0, 0, 0, 0,
                      saved_optional[0x69], saved_optional[0x66],
                      0x20D, (int)D_801AF000);
        *(u32 *)(optional_child + 4) = *(u32 *)(saved_optional + 4);
        func_800428EC(optional_child, -1);
        *(u16 *)(optional_child + 8) |= 8;
        *(u32 *)(optional_child + 4) |= 0x60000000;
        *(u32 *)(saved_optional + 4) |= 0x50000000;
    }
    *(u16 *)(saved_primary + 0x48) = 0xA0;
    *(u16 *)(saved_primary + 0x4A) = 0x78;
    *(u32 *)(saved_primary + 4) &= 0xF7FFFFFF;
    primary_child = func_800400AC(func_8004002C(), 2);
    func_800428A8(primary_child, 0, 0, 0, 0,
                  saved_primary[0x69], saved_primary[0x66],
                  0x20D, (int)D_801AF000);
    *(u32 *)(primary_child + 4) = *(u32 *)(saved_primary + 4);
    func_800428EC(primary_child, -1);
    *(u16 *)(primary_child + 8) |= 8;
    *(u32 *)(primary_child + 4) |= 0x60000000;
    *(u32 *)(primary_child + 0x48) = *(u32 *)(saved_primary + 0x48);
    *(u32 *)(saved_primary + 4) |= 0x50000000;
    i = 0;
    top = 0x80;
    do {
        register int color asm("$5");
        int upper = (i << 16) | (i << 8);
        asm("or %0,%1,%2" : "=r"(color) : "r"(upper), "r"(i));
        *(u32 *)(saved_primary + 0x0C) = color;
        *(u32 *)(primary_child + 0x0C) = color;
        if (saved_optional != 0) {
            int scale_base;
            int inverse_upper;
            int scale;
            color = top - i;
            scale_base = color * 3;
            inverse_upper = (color << 16) | (color << 8);
            asm("or %0,%0,%1" : "+r"(color) : "r"(inverse_upper));
            scale = 0x1000 + scale_base * 32;
            *(u16 *)(primary_child + 0x46) = scale;
            *(u16 *)(primary_child + 0x44) = scale;
            *(u16 *)(saved_primary + 0x46) = scale;
            *(u16 *)(saved_primary + 0x44) = scale;
            *(u32 *)(saved_optional + 0x0C) = color;
            *(u32 *)(optional_child + 0x0C) = color;
        }
        func_80012D4C();
        i += 8;
    } while (i < 0x81);
    *(u32 *)(saved_primary + 0x44) = 0x10001000;
    *(u32 *)(saved_primary + 4) =
        (*(u32 *)(saved_primary + 4) | 0x08000000) & 0x8FFFFFFF;
    func_8004036C(saved_optional);
    func_8004036C(optional_child);
    func_8004036C(primary_child);
}
