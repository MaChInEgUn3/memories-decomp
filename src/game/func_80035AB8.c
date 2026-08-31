typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef struct {
    u8 pad_00[0x3C];
    s16 field_3C;
    s16 field_3E;
    s16 field_40;
    s16 field_42;
    u8 pad_44[0x20];
} Entry100;
extern Entry100 D_800EB0F8[];
void func_80035AB8(int index, int first, int second, int third, int fourth)
{
    Entry100 *entry = &D_800EB0F8[index];
    entry->field_3C = first;
    entry->field_40 = second;
    entry->field_3E = third;
    entry->field_42 = fourth;
}
