typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
extern u8 D_800F5768[];
extern u8 *D_8009B074;
extern u8 *func_800591FC(void);
extern u8 *func_80059208(void);
extern void func_80058FB0();

void func_8005F070(s32 enabled)
{
    u8 *left = func_800591FC();
    u8 *right = func_80059208();

    *(u16 *)(D_800F5768 + 0) = *(u16 *)(left + 0);
    *(u16 *)(D_800F5768 + 2) = *(u16 *)(left + 4);
    *(u16 *)(D_800F5768 + 4) = *(u16 *)(left + 8);
    *(u16 *)(D_800F5768 + 8) = *(u16 *)(left + 12);
    *(u16 *)(D_800F5768 + 10) = *(u16 *)(left + 16);
    *(u16 *)(D_800F5768 + 12) = *(u16 *)(left + 20);
    *(u16 *)(D_800F5768 + 16) = *(u16 *)(right + 0);
    *(u16 *)(D_800F5768 + 18) = *(u16 *)(right + 2);
    *(u16 *)(D_800F5768 + 20) = *(u16 *)(right + 4);
    if (enabled != 0) {
        u8 *table = D_8009B074;
        if (table != (u8 *)0) {
            s32 i = 0;
            s32 offset = 16;
            u8 *entry = table;
            for (; i < 2; offset += 8, i++, entry += 8) {
                s32 kind = *(s16 *)(entry + 6);
                if (kind < 4) {
                    if (kind >= 2)
                        func_80058FB0(*(s16 *)entry, table + offset);
                }
            }
        }
    }
}
