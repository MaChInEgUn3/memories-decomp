typedef unsigned char u8;
typedef unsigned short u16;

extern u8 *D_8009B458;
extern void func_8004A0FC(void *, void *);
extern void func_8004A27C(int, int, int);

void func_8004A2F8(void)
{
    register u8 *state asm("$6") = D_8009B458;
    register int i asm("$17");
    register int object_offset asm("$18");
    register int offset asm("$16");
    if (*(short *)(state + 0x510) > 0) {
        int count;
        i = 0;
        object_offset = 0x180;
        offset = i;
        do {
            u8 *entry = state + offset;
            if (entry[0x183] < 16) {
                int value = entry[0x183];
                u8 *current;
                func_8004A0FC(state + object_offset, state + value * 24);
                current = D_8009B458;
                func_8004A27C(i, *(u16 *)(current + offset + 0x194),
                              *(u16 *)(current + offset + 0x196));
            }
            object_offset += 40;
            asm volatile("" : "+r"(object_offset));
            state = D_8009B458;
            count = *(short *)(state + 0x510);
            asm volatile("" : "+r"(count));
            i++;
            offset += 40;
        } while (i < count);
    }
}
