typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
extern s32 D_8009B0D8;
extern s32 func_80039AAC();

void func_80039AFC(u8 *record)
{
    if (func_80039AAC(record) == 0) {
        record[21] = 2;
        *(s32 *)(record + 4) = 0;
        record[20] = 32;
    }
    record[20] = record[20] - D_8009B0D8 * 2;
    if ((record[19] & 64) == 0) {
        record[4] = record[4] + D_8009B0D8 * 16;
        if ((s8)record[4] < 0) {
            record[4] = 128;
            record[20] = 16;
            record[19] |= 64;
        }
        record[6] = record[4];
    } else {
        record[5] = record[5] + D_8009B0D8 * 16;
        if ((s8)record[5] < 0) {
            record[20] = 0;
            record[21] = 0;
            record[19] = 0;
        }
        record[7] = record[5];
    }
}
