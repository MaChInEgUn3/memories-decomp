typedef struct {
    unsigned char pad[0x334];
    int field334;
} Object;

int func_8003D288(Object *left, Object *right)
{
    int i;

    if (left->field334 == right->field334) {
        i = 6;
        while (--i >= 0) {
        }
        return 1;
    }
    return 0;
}
