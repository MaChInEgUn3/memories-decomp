typedef unsigned char u8;
typedef unsigned short u16;

extern u8 *g_SDValue;
extern void func_80049C40(void);
extern void func_80049CB0(int);
extern void func_800498F8(int);

void func_80049010(void)
{
    register u8 *initial asm("$2") = g_SDValue;
    register int current asm("$4") = *(short *)(initial + 0x157E);
    if (current != -1) {
        if (*(u16 *)(initial + 0x40) & 0x80) {
            register u8 *clear_state asm("$3");
            func_80049C40();
            clear_state = g_SDValue;
            *(u16 *)(clear_state + 0x40) &= 0xFF7F;
        }
        {
            register u8 *call_state asm("$2") = g_SDValue;
            func_80049CB0(*(short *)(call_state + 0x157E));
        }
        {
            register u8 *reset_state asm("$2") = g_SDValue;
            *(short *)(reset_state + 0x157E) = -1;
        }
    }
    {
        register u8 *check_state asm("$2") = g_SDValue;
        if (*(short *)(check_state + 0x157A) == 0) {
            register u8 *fail_state asm("$3");
            func_800498F8(0);
            fail_state = g_SDValue;
            *(short *)(fail_state + 0x157A) = -1;
            *(short *)(fail_state + 0x1578) = -1;
        }
    }
    {
        register u8 *final asm("$2") = g_SDValue;
        *(short *)(final + 0x1588) = 0;
        *(short *)(final + 0x1586) = 0;
    }
}
