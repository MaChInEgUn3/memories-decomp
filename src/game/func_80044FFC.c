typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

struct S80044FFC {
    u8 tag;
    u8 f11;
    s16 f12;
    u8 pad[0x18 - 0x14];
    s32 f18;
    u8 pad2[0x30 - 0xC];
};

extern s32 func_80045BE8(struct S80044FFC *a0);

/* Builds a 0x30-byte request struct on the stack and forwards it to
   func_80045BE8: tag=41, f18=sign-extended low 16 bits of a0, f12=a1's low
   byte, f11=a2's low byte. */
s32 func_80044FFC(s32 a0, s32 a1, s32 a2) {
    struct S80044FFC s;
    s.tag = 41;
    s.f18 = (s16) a0;
    s.f12 = (s16) (u8) a1;
    s.f11 = (u8) a2;
    return func_80045BE8(&s);
}
