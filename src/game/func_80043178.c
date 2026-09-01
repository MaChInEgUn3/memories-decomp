#include "../types.h"

typedef struct {
    unsigned char pad0[0x30];
    unsigned short field30;
    unsigned short field32;
    unsigned char pad34[2];
    unsigned short field36;
    unsigned short field38;
} Object;

void func_80043178(Object *object)
{
    object->field36 = object->field30;
    object->field38 = object->field32;
}
