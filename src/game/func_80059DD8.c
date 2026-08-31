typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
extern u8 D_800F2C40[];
extern s32 func_8005FC1C(s32);
extern void func_8005A53C();

void func_80059DD8(s32 index)
{
    u8 *base = D_800F2C40 + index * 3616;
    u8 *slot = base;
    s32 (*callback)(s32) = func_8005FC1C;
    u8 *node;
    u8 *next;
    s32 i;

    if (base[3615] == 0)
        return;
    for (i = 0; i < base[3610]; i++, slot += 8) {
        node = *(u8 **)(slot + 4);
        if (node != (u8 *)0) {
            while (1) {
                if (*(s32 *)(node + 8) != 0)
                    func_8005A53C(callback, node + 12,
                                  *(s32 *)(node + 4), *(s32 *)(node + 8));
                next = *(u8 **)node;
                if (next == (u8 *)-1)
                    break;
                node = next;
            }
        }
    }
}
