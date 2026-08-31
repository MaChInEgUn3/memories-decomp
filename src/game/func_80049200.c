typedef unsigned char u8;

extern u8 *D_8009B45C;
extern void func_80049230(short, int);

void func_80049200(int value)
{
    func_80049230((short)value, D_8009B45C[0x164B]);
}
