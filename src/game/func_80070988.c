typedef struct {
    int first;
    int addend;
    int result;
} State;

extern State D_800F5BE8;
extern int func_800705AC(void);

void func_80070988(void)
{
    int result = func_800705AC();
    register State *state = &D_800F5BE8;

    
    state->result = result + state->addend;
}
