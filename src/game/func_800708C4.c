typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;

typedef struct {
    s16 unk0;
    u8 pad2[6];
    s8 unk8;
    u8 pad9[3];
} EntryC;

extern EntryC D_801AB000[];
extern u8 gAiScript_State[];

s32 func_800708C4(s32 arg0)
{
    s32 v;
    s32 i;
    u8 *q;

    v = D_801AB000[arg0].unk8;
    i = 0;
    q = gAiScript_State;
    for (; i < 0x19; i++) {
        if (v == q[i + 0x7E] - 1) {
            return 1;
        }
    }
    return 0;
}
