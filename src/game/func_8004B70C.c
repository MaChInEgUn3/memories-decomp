typedef struct {
    unsigned char pad0[7];
    unsigned char value;
    unsigned char pad8[16];
} Entry24;

extern Entry24 *D_8009B458;

void func_8004B70C(unsigned char index, int unused, int value)
{
    register Entry24 *entries = D_8009B458;

    entries += index;
    
    entries->value = value & 0x7F;
}
