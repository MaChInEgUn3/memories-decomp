typedef unsigned char u8;

extern u8 *D_8009B45C;
extern void func_800495DC(void);
extern void func_800495EC(void);
extern void func_80044DC0(int);

void func_80046FA0(short value)
{
    u8 *state = D_8009B45C;
    if (state[0x48] != value) {
        state[0x48] = value;
        if (value == 0)
            func_800495DC();
        else
            func_800495EC();
        func_80044DC0(*(short *)(D_8009B45C + 0x510));
    }
}
