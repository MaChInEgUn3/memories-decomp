typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u16 D_801C0000[];
extern u16 D_801D5800[];
extern u16 D_801B0000[];

u32 func_8003B744(s32 arg0, s32 arg1)
{
    s32 index = arg1;
    if (index > 0xCFFF)
        return ((u32)D_801C0000 & 0xFFFF0000) |
            D_801C0000[index - 0xD000];
    if (index > 0x7FFF)
        return ((u32)D_801D5800 & 0xFFFF0000) |
            D_801D5800[index - 0x8000];
    if (index >= 0x500)
        index -= 0x100;
    return ((u32)D_801B0000 & 0xFFFF0000) | D_801C0000[index];
}
