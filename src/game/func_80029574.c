typedef struct {
    int value_0;
    int value_4;
    unsigned char padding[0x38];
} Entry800EA0E8;

extern Entry800EA0E8 D_800EA0E8[];

void func_80029574(int index)
{
    Entry800EA0E8 *entry = &D_800EA0E8[index];

    entry->value_4 = 0;
    entry->value_0 = 0;
}
