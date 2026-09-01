typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

extern s32 D_80090E0C[];

void Text_EncodeDecimalDigits(s32 arg0, s32 arg1, u8 *arg2) {
    s32 d = D_80090E0C[arg1];
    s32 i;

    i = arg1 - 1;
    do {
        arg2[i] = arg0 / d;
        arg0 -= arg2[i] * d;
        d /= 10;
        i--;
    } while (i >= 0);
    i = arg1 - 1;
    while (i > 0) {
        if (arg2[i] != 0) {
            break;
        }
        arg2[i] = 0xA;
        i--;
    }
}
