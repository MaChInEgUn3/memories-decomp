typedef struct {
    unsigned char pad0[0x24F];
    unsigned char field24F;
} Object;

extern Object D_801D0000;

int func_8002C570(int offset)
{
    Object *object;

    object = (Object *)((unsigned int)&D_801D0000 + offset);
    if (object->field24F) {
        return 1;
    }
    return -1;
}
