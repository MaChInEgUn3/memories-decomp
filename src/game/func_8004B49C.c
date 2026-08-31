typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
extern u8 *D_8009B458;
extern int func_8004A0FC();
extern int func_8004A27C();
extern int func_8004A2F8();
extern int func_8004ACE4();

void func_8004B49C(s32 arg0, s32 arg1, u8 arg2) {
    u8 *b;
    u8 *c;
    u8 *e;
    u8 *q;
    u8 *p;
    u8 ok;
    s32 id;
    s32 id2;
    s32 sel;
    s32 v;
    s32 i;
    s32 k;
    s32 m;
    s32 off;

    ok = 0;
    id = arg0 & 0xFF;
    b = D_8009B458;
    e = b + id * 0x18;
    sel = arg1 & 0xFF;

    switch (sel) {
    case 6:
        v = e[0x12];
        e[0x13] = arg2;
        if (v != 0x14) {
            if (v != 0x1E) {
                func_8004ACE4(e, id);
            }
        }
        break;
    case 7:
        e[3] = arg2;
        ok = 1;
        break;
    case 0xA:
        if (arg2 != 0) {
            e[1] = arg2;
        } else {
            e[1] = 1;
        }
        ok = 1;
        break;
    case 0xB:
        e[5] = arg2;
        ok = 1;
        break;
    case 0x1E:
        *(s16 *)(b + 0x512) = arg2;
        func_8004A2F8();
        break;
    case 0x30:
        e[6] = (e[6] & 0xF) | ((arg2 & 0xF) << 4);
        break;
    case 0x5B:
        e[0x10] = arg2 & 0x7F;
        break;
    case 0x62:
        e[0x11] = arg2;
        break;
    case 0x63:
        e[0x12] = arg2;
        break;
    
    case 0x7F:
        break;
    }

    if (ok != 0) {
        c = D_8009B458;
        i = 0;
        if (*(s16 *)(c + 0x510) > 0) {
            id2 = arg0 & 0xFF;
            off = id2 * 0x18;
            m = 0x180;
            k = i;
            do {
                q = c + k;
                if (id2 == q[0x183]) {
                    if (q[0x18D] != 0) {
                        func_8004A0FC(c + m, c + off);
                        p = D_8009B458 + k;
                        func_8004A27C(i, *(u16 *)(p + 0x194), *(u16 *)(p + 0x196));
                    }
                }
                m += 0x28;
                k += 0x28;
                c = D_8009B458;
                i++;
            } while (i < *(s16 *)(c + 0x510));
        }
    }
}
