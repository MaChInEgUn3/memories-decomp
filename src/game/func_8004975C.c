#include "../types.h"
#include "sound.h"

extern void func_800771B0(void *);
extern int func_80077150(int, int);

int func_8004975C(int value, short expected)
{
    register int saved;
    SDSecondaryState *state = D_8009B458;
    short current = state->transfer.field_0000;
    if (current != expected)
        return -1;
    saved = value;
    {
        SDSecondaryTransfer *entry = &state->transfer;
        func_800771B0(entry->field_0014);
        if (func_80077150(saved, entry->field_0010) !=
            entry->field_0010)
            return -1;
        entry->field_000C = saved;
    }
    return current;
}
