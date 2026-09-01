typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
typedef struct LocalRec12 {
    s16 unk0;
    u8 pad2[10];
} LocalRec12;
extern u8 gAiScript_State[];
extern LocalRec12 D_801AB000[];
extern int func_80019A08();
extern int func_80019A60();
extern int func_8002CBF4();
extern int func_80070920();

void func_800727C0(s32 arg0) {
    u8 *p;
    u8 *a;
    s32 i;
    s32 k;
    s32 v;
    s32 n;
    s32 m;

    a = (u8 *)gAiScript_State;
    i = 0;
    if (a[0x9C] == 0) {
        return;
    }
    p = a;
    do {
        if (p[i + 0xAA] == 0) {
            v = D_801AB000[i + 0xB].unk0;
            k = i + 0xB;
            if (v != 0) {
                if (func_80070920(p[0x9E], k) == 0) {
                    n = func_80019A60(arg0, v);
                    if (n == 0) {
                        n = func_80019A08(arg0, v);
                    }
                    if (n != 0) {
                        p[p[0xA2] + 0xA4] = k;
                        if (func_8002CBF4(n, 0) > *(u16 *)(p + 0xA0) ||
                            (func_8002CBF4(n, 0) == *(u16 *)(p + 0xA0) &&
                             p[0xA2] < p[0xA3])) {
                            *(u16 *)(p + 0xA0) = func_8002CBF4(n, 0);
                            p[0xA3] = p[0xA2];
                            for (m = 0; m <= (s32)p[0xA3]; m++) {
                                p[m + 0x38] = p[m + 0xA4];
                            }
                            p[m + 0x38] = 0;
                        }
                        if (func_8002CBF4(n, 1) > *(u16 *)(p + 0xA0) ||
                            (func_8002CBF4(n, 1) == *(u16 *)(p + 0xA0) &&
                             p[0xA2] < p[0xA3])) {
                            *(u16 *)(p + 0xA0) = func_8002CBF4(n, 1);
                            p[0xA3] = p[0xA2];
                            for (m = 0; m <= (s32)p[0xA3]; m++) {
                                p[m + 0x38] = p[m + 0xA4];
                            }
                            p[m + 0x38] = 0;
                        }
                        if (p[0xA2] < p[0x9D] - 1) {
                            p[i + 0xAA] = 1;
                            p[0xA2] = p[0xA2] + 1;
                            func_800727C0(n);
                            p[i + 0xAA] = 0;
                            p[0xA2] = p[0xA2] - 1;
                        }
                    }
                }
            }
        }
        i++;
    } while (i < p[0x9C]);
}
