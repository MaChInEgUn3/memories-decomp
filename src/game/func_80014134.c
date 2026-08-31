typedef unsigned char u8;
extern char D_8009B104[1];
extern int D_8009B130;
extern volatile int D_8009B0F4;
extern void func_8007B468();

void func_80014134(u8 event)
{
    if (event == 5) {
        D_8009B130++;
        func_8007B468(0xA0, D_8009B104, 0x15, func_80014134, -1);
    } else if (event == 2) {
        D_8009B0F4 &= ~0x400;
    }
}
