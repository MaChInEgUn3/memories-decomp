extern short gAiScript_State[];

void func_80073380(void)
{
    register int index asm("$3") = 31;
    register short *position asm("$2") = gAiScript_State;

    asm("" : "+r"(position));
    position += 31;
    do {
        position[31] = 0;
        index--;
        position--;
    } while (index >= 0);
}
