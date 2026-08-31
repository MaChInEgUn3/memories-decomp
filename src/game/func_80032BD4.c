typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;


typedef struct { u32 key; s16 index; } Item;
extern s16 D_801D4D8E[];
s32 func_80032BD4(Item *arg0, Item *arg1) {
    u32 a = arg0->key;
    u32 b = arg1->key;
    if (a == b) {
        if (D_801D4D8E[arg0->index - 1] < D_801D4D8E[arg1->index - 1])
            return -1;
        return 1;
    }
    if (b < a) return 1;
    return -1;
}
