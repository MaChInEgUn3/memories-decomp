typedef unsigned char u8;
typedef unsigned short u16;

extern u8 *D_8009B458;
extern void func_8004BCE8(void);
extern int func_8004BB34(void *);
extern void func_8004C5C8(void *);

int func_8004C77C(void)
{
    register u8 *initial asm("$2") = D_8009B458;
    register int i asm("$17");
    register int offset asm("$18");
    *(int *)(initial + 0x804) = 0;
    initial[0x800] = 0;
    func_8004BCE8();
    {
        register u8 *state asm("$4") = D_8009B458;
        if (*(u16 *)(state + 0x7FA) != 0) {
            int count;
            i = 0;
            offset = 0x518;
            do {
                register u8 *entry asm("$16") = state + offset;
                int value = *(int *)entry;
                *(int *)(entry + 4) = value;
                value = func_8004BB34(entry);
                entry[0x24] = 0;
                entry[0x27] = 0;
                entry[0x29] = 0;
                entry[0x28] = 0;
                {
                    register u8 *flags_state asm("$3") = D_8009B458;
                    *(int *)(entry + 0x1C) = value;
                    *(short *)(entry + 0x18) = 0;
                    if (*(int *)(flags_state + 0x804) != 0)
                        func_8004C5C8(entry);
                }
                state = D_8009B458;
                count = *(u16 *)(state + 0x7FA);
                asm volatile("" : "+r"(count));
                i++;
                offset += 44;
            } while (i < count);
        }
    }
    return 0;
}
