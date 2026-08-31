typedef struct { int key; void **handler; } Object;
extern void *func_8006041C(int); extern void func_80060170(int, int);
void func_8006086C(Object *object)
{
    *object->handler = func_8006041C(object->key);
    func_80060170(object->key, (int)*object->handler);
}
