typedef unsigned char u8;
typedef unsigned short u16;

extern u8 *D_8009B45C;
extern void func_80047A68(void);
extern void func_8004763C(void);
extern void func_80047788(u16);

int func_80047AD0(int value)
{
    u16 index = value;
    u8 *state = D_8009B45C;
    u8 *table = *(u8 **)(state + 0x448);
    if (*(int *)(table + index * 8 + 4) == 0)
        return 1;
    if (*(u16 *)(state + 0x442) == index)
        return 1;
    func_80047A68();
    func_8004763C();
    {
        register u8 *final = D_8009B45C;
        register int call_value = index;
        *(u16 *)(final + 0x442) = value;
        *(u16 *)(final + 0x40) |= 2;
        func_80047788(call_value);
    }
    return 1;
}
