typedef struct {
    unsigned char pad[0x30];
    short field30;
    short field32;
} Child;

typedef struct {
    Child *children[3];
} Object;

void func_8003A920(Object *object, short field30, short field32)
{
    int i;

    for (i = 2; i >= 0; i--) {
        if (object->children[i] != 0) {
            object->children[i]->field30 = field30;
            object->children[i]->field32 = field32;
        }
    }
}
