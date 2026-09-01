#include "../types.h"

extern void *func_8002C604(void);
extern unsigned char D_8009B260;

void *func_8002C68C(void)
{
    void *value = func_8002C604();

    if (value != 0) {
        D_8009B260 |= 0x80;
    }
    return value;
}
