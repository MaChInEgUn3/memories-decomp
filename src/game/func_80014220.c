typedef unsigned short u16;
extern int D_8009B130, D_8009B0F4;
extern u16 D_8009B100;
extern void func_8007B1F4(int, void *, void *, int);

void func_80014220(int event)
{
    event &= 0xFF;
    if (event == 5) {
        D_8009B130++;
        func_8007B1F4(9, 0, func_80014220, -1);
    } else if (event == 2) {
        __asm__ volatile(
            "sh $4, %%gp_rel(D_8009B100)($28)"
            : : : "memory"
        );
        D_8009B0F4 &= ~0x400;
    }
}
