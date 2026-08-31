typedef unsigned char u8;
typedef signed char s8;

extern u8 D_8009B1D5;
extern s8 D_8009B360[9];
extern s8 D_8009B361[9];
extern void func_8002CCE4(void *);

void func_80019CC8(void *object)
{
    if (D_8009B1D5 == 0 && D_8009B360[0] < 0 && D_8009B361[0] >= 0) {
        func_8002CCE4((char *)object + 0x120);
    }
}
