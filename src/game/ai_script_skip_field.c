extern void AiScript_ReadByte(void);

void AiScript_SkipField(void)
{
    AiScript_ReadByte();
    AiScript_ReadByte();
    AiScript_ReadByte();
    AiScript_ReadByte();
}
