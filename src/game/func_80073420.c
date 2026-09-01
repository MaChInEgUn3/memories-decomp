extern unsigned char gAiScript_State[];

void func_80073420(void)
{
    register int index asm("$3") = 24;
    register unsigned char *position asm("$2");

    asm("" : "+r"(index));
    position = gAiScript_State;
    asm("" : "+r"(position));
    position += index;
    asm("" : "+r"(position));
    do {
        position[126] = 0;
        index--;
        position--;
    } while (index >= 0);
}
