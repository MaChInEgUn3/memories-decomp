typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_8009B324;
extern u8 D_8009B325;
extern u8 D_800EAF08[];

s32 func_80035D10(void)
{
    s32 col = D_8009B324;
    s32 row = D_8009B325;
    s32 count = 0x100;
    do {
        s32 index = row * 16 + col;
        if (D_800EAF08[index] == 0)
            return index;
        col++;
        if ((col & 3) == 0) {
            row++;
            if (row >= 0xF)
                row = 0x10;
            if ((row & 3) == 0)
                row -= 4;
            else
                col -= 4;
            if (col >= 0x10) {
                row += 4;
                col = 0;
                if (row >= 0x10)
                    row = 0;
            }
        }
        count--;
    } while (count != 0);
    return -1;
}
