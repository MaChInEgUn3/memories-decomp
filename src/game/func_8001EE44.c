typedef unsigned short u16; typedef signed short s16;
typedef struct { char pad_00[0xC]; s16 id; char pad_0E[8]; u16 flags; } Entry;
extern int D_801D4244[];
extern int func_8002CB80(int, int);

int func_8001EE44(Entry *left, Entry *right)
{
    int left_value, right_value;
    if (right == 0) return 0;
    if (left->flags & 0x200)
        left_value = (D_801D4244[left->id - 1] >> 18) & 0xF;
    else
        left_value = (D_801D4244[left->id - 1] >> 22) & 0xF;
    if (right->flags & 0x200)
        right_value = (D_801D4244[right->id - 1] >> 18) & 0xF;
    else
        right_value = (D_801D4244[right->id - 1] >> 22) & 0xF;
    return func_8002CB80(left_value, right_value);
}
