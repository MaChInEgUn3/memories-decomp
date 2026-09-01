typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

/* Validates a byte value (1..20) and stores it into the s16 field 0x510
   of *D_8009B458 (same field read by get_8009b45c_510.c... note: a
   different global, D_8009B458 not D_8009B45C). Returns the stored value,
   or 0xFF if out of range or zero. */
struct S8009B458 {
    char pad[0x510];
    s16 f510;
};

extern struct S8009B458 *D_8009B458;

s32 func_80049600(u32 a0) {
    u8 x = a0 & 0xFF;

    if (x >= 0x15) {
        return 0xFF;
    }
    if (x == 0) {
        return 0xFF;
    }
    D_8009B458->f510 = x;
    return x;
}
