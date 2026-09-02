#include "../types.h"
#include "sound.h"

int func_8004BAE4(unsigned char *reader)
{
    SDSecondaryState *state = D_8009B458;
    int offset = *(int *)reader;
    int value = state->field_07DC[offset];
    offset++;
    *(int *)reader = offset;
    if ((unsigned int)state->field_07EC < (unsigned int)offset) {
        reader[0x24] = 1;
        return -1;
    }
    return value;
}
