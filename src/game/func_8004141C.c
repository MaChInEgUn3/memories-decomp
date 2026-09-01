#include "../types.h"

typedef struct {
    unsigned char pad[0x5A];
    short field5A;
} Object;

int func_8004141C(Object *object)
{
    object->field5A = 0;
    return -1;
}
