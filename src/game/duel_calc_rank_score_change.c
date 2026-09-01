typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;

typedef struct {
    s16 threshold;
    s16 value;
} Threshold;

extern Threshold gDuel_awRankScoreChange[][5];

s32 Duel_CalcRankScoreChange(s32 arg0, s32 arg1)
{
    Threshold *p = &gDuel_awRankScoreChange[arg0][0];

    while (1) {
        if (arg1 < p->threshold) {
            return p->value;
        }
        p++;
    }
}
