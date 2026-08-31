typedef unsigned char u8;
typedef unsigned short u16;

extern u8 *D_8009B45C;
extern void func_80049010(void);

void func_800493F8(void)
{
    u16 *entry;
    func_80049010();
    entry = (u16 *)0x801EA800;
    *(u16 **)(D_8009B45C + 0x1564) = entry;
    entry[0] = 0xFFFF;
}
