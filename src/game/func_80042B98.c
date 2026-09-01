#include "../types.h"

typedef struct {
    unsigned char pad[0x6C];
    unsigned char flags;
} Object;

int func_80042B98(Object *object)
{
    if ((object->flags & 0x80) == 0) {
        object->flags |= 0x80;
        return 0;
    }
    return 1;
}
