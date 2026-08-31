typedef struct {
    unsigned char pad[0x50];
    unsigned char *current;
    unsigned char *base;
    unsigned short field58;
} Object;

int func_8004143C(Object *object, const unsigned char *data)
{
    object->field58 = 0;
    object->current = object->base + ((data[1] << 8) | data[0]);
    return 1;
}
