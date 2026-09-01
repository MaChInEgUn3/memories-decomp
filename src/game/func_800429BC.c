#include "../types.h"

typedef struct {
    unsigned char pad[0x54];
    unsigned char *base;
} Object;

unsigned char *func_800429BC(Object *object, const unsigned char *data)
{
    return object->base + ((data[1] << 8) | data[0]);
}
