extern void func_80045114(void);
extern void func_80049230(int, short);

void func_800473F0(unsigned int flags, int value)
{
    if ((flags & 0x8000) != 0) {
        func_80045114();
    } else {
        func_80049230(-1, value);
    }
}
