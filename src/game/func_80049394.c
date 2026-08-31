typedef unsigned char u8;
typedef unsigned short u16;

extern u8 *D_8009B45C;
extern void func_80049010(void);

void func_80049394(void *entry)
{
    func_80049010();
    if (entry != 0)
        *(void **)(D_8009B45C + 0x1564) = entry;
    else
        *(void **)(D_8009B45C + 0x1564) = (void *)0x801EA800;
    **(u16 **)(D_8009B45C + 0x1564) = 0xFFFF;
}
