extern unsigned char D_800F5BE8[];

void func_80073420(void)
{
    register int index asm("$3") = 24;
    register unsigned char *position asm("$2");

    asm("" : "+r"(index));
    position = D_800F5BE8;
    asm("" : "+r"(position));
    position += index;
    asm("" : "+r"(position));
    do {
        position[126] = 0;
        index--;
        position--;
    } while (index >= 0);
}
