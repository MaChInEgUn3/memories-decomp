#include "../types.h"

typedef struct { u8 b0, b1, b2, b3; } Word4;
extern void func_80058938(s32, s32, Word4, Word4, s32, s32);

void func_80058838(s32 a0, s32 a1, Word4 a2, Word4 a3, s32 a4, ...)
{
    u8 bits[8];
    u8 *arguments;
    s32 value;
    s32 byte_index;
    s32 i;
    u8 *cursor;

    i = 7;
    cursor = bits + 7;
    for (; i >= 0; i--)
        *cursor-- = 0;
    arguments = (u8 *)&a4 + 4;
    while (1) {
        arguments += 4;
        value = *(s32 *)(arguments - 4);
        if (value < 0)
            break;
        byte_index = value >> 3;
        bits[byte_index] |= 1 << (value - byte_index * 8);
    }
    a2.b3 = a1 & 127;
    func_80058938(a0, a1 & 128, a2, a3, a4, (s32)bits);
}
