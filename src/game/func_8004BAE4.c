#include "../types.h"

extern unsigned char *D_8009B458;
int func_8004BAE4(unsigned char *reader)
{
    unsigned char *state = D_8009B458;
    int offset = *(int *)reader;
    int value = *(unsigned char *)(*(int *)(state + 0x7DC) + offset);
    offset++;
    *(int *)reader = offset;
    if ((unsigned int)*(int *)(state + 0x7EC) < (unsigned int)offset) {
        reader[0x24] = 1;
        return -1;
    }
    return value;
}
