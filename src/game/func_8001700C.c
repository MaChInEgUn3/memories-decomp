#include "../types.h"

typedef struct {
    u8 pad_00[0x16];
    u16 flags;
} Object;

int func_8001700C(Object *object)
{
    u16 flags = object->flags;

    if (flags & 0x8000) {
        if (!(flags & 0x4000)) {
            return 1;
        }
    }
    return 0;
}
