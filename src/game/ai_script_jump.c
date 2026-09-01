typedef struct {
    int first;
    int addend;
    int result;
} State;

extern State gAiScript_State;
extern int AiScript_ReadShort(void);

void AiScript_Jump(void)
{
    int result = AiScript_ReadShort();
    register State *state = &gAiScript_State;

    
    state->result = result + state->addend;
}
