extern unsigned char *D_8009B45C;
extern void func_8004733C(unsigned short, unsigned char);

void func_80047314(unsigned int value)
{
    func_8004733C(value & 0xFFFF, D_8009B45C[0x164B]);
}
