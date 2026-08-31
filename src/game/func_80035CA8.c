typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern u8 D_800EAF08[];
void func_80035CA8(int value)
{
    int index;
    u8 *entry = D_800EAF08;
    value++;
    for (index = 0; index < 0xF0; index++, entry++) {
        if (*entry == value) {
            *entry = 0;
        }
    }
}
