#include "../types.h"

typedef struct { char p[8]; u16 flags; } Object;
extern void *func_8004006C(void);
extern Object *func_800400AC(void *, int);
extern void func_800404CC();
extern void func_80042918(Object *);
extern void func_800428EC(Object *, int);

Object *func_80018150(int arg0, int arg1)
{
    Object *object = func_800400AC(func_8004006C(), 2);
    func_800404CC(object, arg0, arg1, 0, 1, 0, 0x1F, 0x100);
    func_80042918(object);
    func_800428EC(object, -2);
    object->flags |= 8;
    return object;
}
