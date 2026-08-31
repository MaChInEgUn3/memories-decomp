typedef struct {
    unsigned char pad[0x14];
    short field14;
    signed char field16;
    unsigned char field17;
} Object;

extern unsigned short D_8009AF76;

void func_80042918(Object *object)
{
    object->field17 = 1;
    object->field14 = D_8009AF76 - object->field16;
}
