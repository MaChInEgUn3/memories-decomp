typedef unsigned char u8;
typedef unsigned short u16;

void func_800389C4(u8 *value)
{
    *(u16 *)(value + 0x34) &= (u16)~8;
}
