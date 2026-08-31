extern short D_800F5BE8[];

void func_80073380(void)
{
    register int index asm("$3") = 31;
    register short *position asm("$2") = D_800F5BE8;

    asm("" : "+r"(position));
    position += 31;
    do {
        position[31] = 0;
        index--;
        position--;
    } while (index >= 0);
}
