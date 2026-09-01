#include "../types.h"

typedef struct { unsigned char enabled; unsigned char busy; unsigned short value; } State;
extern State D_800F2B20;
int func_8005A878(int arg)
{
    int result = 0;
    if (D_800F2B20.busy == 0) {
        if (arg != 0 || D_800F2B20.enabled == 0 || D_800F2B20.value == 0)
            result = 1;
    }
    return result;
}
