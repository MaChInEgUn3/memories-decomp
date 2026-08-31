typedef struct {
    unsigned char pad0[0x19];
    unsigned char field19;
} Object;

extern void func_80023D08(Object *);

int func_80024088(Object *object)
{
    func_80023D08(object);
    return object->field19;
}
