extern void func_800472A8(unsigned int);
extern void func_80047AD0(unsigned int);

void func_80047278(unsigned int value)
{
    func_800472A8(value >> 16);
    func_80047AD0(value & 0xFFFF);
}
