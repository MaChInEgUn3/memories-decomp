typedef struct {
    unsigned char pad[0x58];
    short field58;
} Object;

int func_80041428(Object *object)
{
    object->field58 = 0;
    return 1;
}
