typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;

typedef void (*Handler)(u8 *);
extern Handler D_80090EAC[];

void func_80038B4C(u8 *arg0)
{
    u8 **pp = (u8 **)(arg0 + *(s8 *)(arg0 + 0x58) * 4);
    u8 *p = *pp;
    s32 op = *p;

    *pp = p + 1;
    D_80090EAC[op](arg0);
}
