#include "../types.h"

typedef struct {
    unsigned char pad0[8];
    unsigned short flags;
    unsigned char padA[0x5F];
    unsigned char field69;
} Object;

void func_80040424(Object *object, int value)
{
    if (object->field69 != value) {
        object->field69 = value;
        object->flags &= 0xFFEF;
    }
}
