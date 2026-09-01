#include "../types.h"

int func_80042960(char *object)
{
    void (*callback)(void) = *(void (**)(void))(object + 0x24);
    if (callback != 0)
        callback();
    return ((*(u16 *)(object + 8) & 0xC0) == 0xC0);
}
