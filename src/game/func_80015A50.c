#include "../types.h"

typedef struct { int x; u8 a, b, flags, mode, pad[4]; } State;
extern State D_800E9EC8;
extern void func_80015780(void);
extern void func_8001572C(void);
extern void func_80015998(void);

void func_80015A50(void)
{
    State *state;

    func_80015780();
    state = &D_800E9EC8;
    state->flags |= 2;
    func_8001572C();
    func_80015998();
}
