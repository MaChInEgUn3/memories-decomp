typedef struct {
    int first;
    int addend;
    int result;
} State;

extern State gAiScript_State;
extern int func_800705AC(void);

void func_80070988(void)
{
    int result = func_800705AC();
    register State *state = &gAiScript_State;

    
    state->result = result + state->addend;
}
