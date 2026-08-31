typedef signed short s16;
typedef unsigned char u8;

typedef struct {
    u8 pad_00[0x30];
    s16 field_30;
    s16 field_32;
} Object;

extern void func_80016784(Object *, int, int, int);

void func_80016D04(Object *object, int arg1)
{
    func_80016784(object, arg1, object->field_30, object->field_32);
}
