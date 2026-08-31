typedef struct { int key; void **handler; } Object;
extern void *func_800608B8(int); extern void func_80060170(int, int);
void func_80060AEC(Object *object)
{
    *object->handler = func_800608B8(object->key);
    func_80060170(object->key, (int)*object->handler);
}
