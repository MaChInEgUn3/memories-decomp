typedef unsigned char u8;
typedef unsigned short u16;

extern u8 *g_SDValue;

void func_8004763C(void)
{
    register u8 *state asm("$5") = g_SDValue;
    register int i asm("$4") = *(u16 *)(state + 4);
    register int count asm("$2") = *(u16 *)state;
    register int sentinel asm("$3") = 0xFFFF;
    *(u16 *)(state + 0x442) = sentinel;
    if (i < count) {
        register int fill asm("$6") = sentinel;
        do {
            ((u16 *)*(void **)(state + 0x43C))[i] = fill;
            i++;
            count = *(u16 *)state;
        } while (i < count);
    }
    {
        u8 *final = g_SDValue;
        *(u16 *)(final + 0x440) = *(u16 *)(final + 4);
        *(int *)(final + 0x438) =
            *(int *)(*(u8 **)(final + 0x448) + 4) + 0x1010;
    }
}
