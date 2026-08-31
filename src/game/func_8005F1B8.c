typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

struct Local {
    u8 pad[6];
    s16 f6;
};
extern void func_80059000(s32, struct Local *);

s32 func_8005F1B8(s32 level, s32 val) {
    struct Local local;
    s16 delta;

    if (level >= 2) {
        return val;
    }

    func_80059000(level, &local);

    if (local.f6 < 50) {
        local.f6 = 50;
    }

    local.f6 -= 300;
    delta = local.f6;

    if (delta != 0) {
        s32 divisor = 750;
        s32 half = val;
        if (delta > 0) {
            half = (s32)(val + ((u32)val >> 31)) >> 1;
        }
        val += (delta * half) / divisor;
    }

    return val;
}
