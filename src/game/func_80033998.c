typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern u8 *D_8009B2FC;
int func_80033998(void)
{
    int index;
    u8 *entry = D_8009B2FC + 0x2D50;
    for (index = 0; index < 0x28; index++, entry += 0x10) {
        if (entry[0xD] == 0) {
            return 1;
        }
    }
    return 0;
}
