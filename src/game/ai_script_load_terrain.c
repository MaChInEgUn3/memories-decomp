extern int gAiScript_aMemory[];
extern unsigned char gDuel_bTerrain;
extern int AiScript_ReadByte(void);

void AiScript_LoadTerrain(void)
{
    int index = AiScript_ReadByte();
    register int *values asm("$3") = gAiScript_aMemory;
    register unsigned int value asm("$4");

    asm("" : "+r"(values));
    value = gDuel_bTerrain;
    values[index] = value;
}
