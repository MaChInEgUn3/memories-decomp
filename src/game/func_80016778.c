#include "../types.h"

typedef struct {
    u8 pad_00[0x69];
    u8 field_69;
} Object;

void func_80016778(Object *object, u32 value)
{
    object->field_69 = value >> 31;
}
