#include "../types.h"

typedef struct {
    unsigned char pad0[0x30];
    short field30;
    unsigned char pad32[4];
    short field36;
    unsigned char pad38[0x2A];
    unsigned char field62;
} Object;

void func_80042A00(Object *object)
{
    int value = (object->field30 << 8) | object->field62;

    value += object->field36;
    object->field62 = value;
    object->field30 = value >> 8;
}
