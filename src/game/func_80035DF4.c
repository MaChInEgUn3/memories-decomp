typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef struct {
    u8 pad_00[0x11];
    u8 field_11;
    u8 pad_12[6];
    u8 field_18;
    u8 pad_19[3];
} Entry28;
extern Entry28 D_800EB288[];
void func_80035DF4(void)
{
    int remaining = 0x26C;
    register Entry28 *base asm("$2") = D_800EB288;
    u8 *entry;
    asm("" : "+r"(base));
    entry = &base->field_18;
    do {
        entry[-7] = 0;
        entry[0] = 0;
        entry += sizeof(Entry28);
    } while (--remaining != 0);
}
