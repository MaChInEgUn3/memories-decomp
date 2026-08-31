typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
extern u8 D_80010538[];
extern void func_8008F200();
extern void *func_80073AC0();
extern void *func_80073920();

s32 func_80044470(s32 a0, s32 a1, u8 *cursor, s32 *out_count)
{
    u8 work[32];
    s32 retry;
    s32 count;

    func_8008F200(work, D_80010538, a0, a1);
    retry = 5;
    while ((u8 *)func_80073AC0(work, cursor) != cursor) {
        retry--;
        if (retry < 0)
            return 0;
    }
    retry = 5;
    count = 1;
    cursor += 40;
    do {
        if ((u8 *)func_80073920(cursor) != cursor) {
            retry--;
            if (retry < 0)
                break;
        } else {
            retry = 5;
            cursor += 40;
            count++;
        }
    } while (count < 15);
    if (out_count != (s32 *)0)
        *out_count = count;
    return count;
}
