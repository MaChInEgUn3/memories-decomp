typedef unsigned char u8;
typedef unsigned short u16;

extern u8 *D_8009B458;

void func_8004C84C(void)
{
    u8 *state = D_8009B458;
    register int i asm("$5") = 0;
    if (*(short *)(state + 0x510) > 0) {
        register int offset asm("$6") = 0x180;
        int count;
        do {
            u8 *entry = state + offset;
            u16 value = *(u16 *)(entry + 0x1E);
            if (value != 0 && entry[3] < 16)
                *(u16 *)(entry + 0x1E) = value - 1;
            else
                *(u16 *)(entry + 0x1E) = 0;
            state = D_8009B458;
            count = *(short *)(state + 0x510);
            asm volatile("" : "+r"(count));
            i++;
            offset += 40;
        } while (i < count);
    }
}
