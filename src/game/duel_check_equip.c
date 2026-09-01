typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;

extern u16 gDuel_awEquipTable[];

s32 Duel_CheckEquip(s32 arg0, s32 arg1)
{
    u16 *p = gDuel_awEquipTable;

    while (1) {
        s32 key = p[0];
        s32 n;

        if (key == 0) {
            return 0;
        }
        n = p[1];
        p += 2;
        if (key == arg0) {
            do {
                if (arg1 == *p) {
                    return arg1;
                }
                n--;
                p++;
            } while (n != 0);
            return 0;
        }
        p += n;
    }
}
