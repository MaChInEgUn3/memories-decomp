typedef struct {
    unsigned char pad[0x54];
    void *field54;
} Object;

extern void func_80040468(Object *, int, int, int, int, int);

void func_80042874(
    Object *object,
    int arg1,
    int arg2,
    int arg3,
    int arg4,
    int arg5,
    void *field54)
{
    object->field54 = field54;
    func_80040468(object, arg1, arg2, arg3, arg4, arg5);
}
