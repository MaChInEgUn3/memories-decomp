#include "../types.h"

typedef struct {
    unsigned char pad[0x14];
    short field14;
    signed char field16;
    unsigned char field17;
} Object;

extern unsigned short D_8009AF7A;

void func_8004293C(Object *object)
{
    object->field17 = 3;
    object->field14 = D_8009AF7A - object->field16;
}
