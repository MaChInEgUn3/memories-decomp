#include "../types.h"

typedef struct { int key; void **handler; } Object;
extern void *Model_GetPrimitiveHandler(int); extern void Model_RegisterHandlerKey(int, int);
void func_8006086C(Object *object)
{
    *object->handler = Model_GetPrimitiveHandler(object->key);
    Model_RegisterHandlerKey(object->key, (int)*object->handler);
}
