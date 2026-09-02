#include "../types.h"

typedef struct { int key; void **handler; } Object;
extern void *func_800608B8(int); extern void Model_RegisterHandlerKey(int, int);
void func_80060AEC(Object *object)
{
    *object->handler = func_800608B8(object->key);
    Model_RegisterHandlerKey(object->key, (int)*object->handler);
}
