typedef unsigned char u8;

extern u8 *D_8009B458;
extern void func_8004CA60(void);
extern void func_8004A518(void);

void func_80049C40(void)
{
    u8 *initial = D_8009B458;
    if (*(short *)(initial + 0x7E0) != -1) {
        u8 *state;
        u8 *other;
        initial[0x500] = 1;
        func_8004CA60();
        func_8004A518();
        state = D_8009B458;
        state[0x500] = 0;
        other = D_8009B458;
        *(short *)(state + 0x7E6) = 127;
        *(short *)(state + 0x7E4) = 127;
        *(short *)(state + 0x7E2) = 2;
        other[0x502] = 0;
    }
}
