typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

struct Rec7 {
    s32 f[7];
};

extern s32 func_80058A7C(s32 a0, s32 a1, struct Rec7 *a2);

/* Copies the 7-word struct onto the stack before forwarding it, so the
   callee can't alias the caller's copy. */
s32 func_80059A50(s32 a0, s32 a1, struct Rec7 *src) {
    struct Rec7 buf = *src;
    return func_80058A7C(a0, a1, &buf);
}
