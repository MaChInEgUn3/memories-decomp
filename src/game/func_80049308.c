typedef unsigned char u8;
typedef unsigned short u16;

extern u8 *D_8009B45C;
extern int func_800496C4(void *, int, int);

void func_80049308(void)
{
    u8 *state = D_8009B45C;
    if (*(short *)(state + 0x157A) != 0) {
        u8 *entry = *(u8 **)(state + 0x1564);
        int result = func_800496C4(entry + 0x50, 0, *(int *)(entry + 0x0C));
        *(short *)(D_8009B45C + 0x157A) = result;
        if ((result << 16) != 0) {
            *(short *)(D_8009B45C + 0x1578) = -1;
            *(short *)(D_8009B45C + 0x157A) = -1;
            return;
        }
    }
    {
        register u8 *final asm("$2") = D_8009B45C;
        register u16 *entry asm("$3") = *(u16 **)(final + 0x1564);
        *(u16 *)(final + 0x1578) = *entry;
    }
}
