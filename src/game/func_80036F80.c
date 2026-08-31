typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;


extern u8 D_8009B336;
extern s8 D_8009B34D;
extern void func_80036DBC(void *);
void func_80036F80(u8 *arg0) {
    s32 value;
    u8 *sub = *(u8 **)(arg0 + 0x30);
    if (((D_8009B336 >> D_8009B34D) & 1) == 0) value = 0xC0;
    else value = 0xC0C0;
    *(s32 *)(sub + 0x0C) = value;
    *(s32 *)(*(u8 **)(arg0 + 0x30) + 0x3C) = value;
    *(s32 *)(*(u8 **)(arg0 + 0x30) + 0x44) = value;
    value = value / 4;
    *(s32 *)(*(u8 **)(arg0 + 0x30) + 0x2C) = value;
    *(s32 *)(*(u8 **)(arg0 + 0x30) + 0x34) = value;
    *(s32 *)(*(u8 **)(arg0 + 0x30) + 0x4C) = value;
    *(s32 *)(*(u8 **)(arg0 + 0x30) + 0x54) = value;
    func_80036DBC(arg0);
}
