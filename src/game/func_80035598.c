typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
int func_80035598(const u32 *left, const u32 *right)
{
    if (*left == *right) {
        return 0;
    }
    if (*left >= *right) {
        return 1;
    }
    return -1;
}
