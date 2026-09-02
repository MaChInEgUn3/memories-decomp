#include "../types.h"

extern void func_80035AB8(int,int,int,int,int);
extern unsigned char *DuelEffect_InitEntry(int,int,int);
unsigned char *func_80035C38(int a,int b,int c,int d,int e,int f,int g) {
    unsigned char *result;
    func_80035AB8(a,c,d,e,f);
    result = DuelEffect_InitEntry(a,b,0);
    *(unsigned short *)(result + 0x34) |= g;
    return result;
}
