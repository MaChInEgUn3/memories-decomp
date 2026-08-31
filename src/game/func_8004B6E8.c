typedef struct {
    unsigned char value;
    unsigned char pad1[23];
} Entry24;

extern Entry24 *D_8009B458;

void func_8004B6E8(unsigned char index, int value)
{
    register Entry24 *entries asm("$3") = D_8009B458;

    entries += index;
    asm("" : "+r"(entries));
    entries->value = value;
}
