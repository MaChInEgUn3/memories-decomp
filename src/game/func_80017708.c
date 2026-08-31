typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;


extern u8 D_800E9F10[];
void func_80017708(void) {
    s32 row, j;
    for (row = 0; row < 2; row++) {
        u8 *p = D_800E9F10 + row * 0x70;
        for (j = 0; j < 4; p += 0x1C, j++) {
            *(u32 *)(p + 0x00) = 0;
            *(u32 *)(p + 0x04) = 0;
            *(u32 *)(p + 0x08) = 0;
            p[0x18] = 0;
            p[0x13] = 1;
            p[0x17] = j;
            p[0x14] = (j != 3) ? j : 1;
        }
    }
    D_800E9F10[0x13] = 0;
    D_800E9F10[0x83] = 0;
}
