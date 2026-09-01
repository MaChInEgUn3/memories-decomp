typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

extern s32 AiScript_ReadByte(void);

/* Same 4-byte-stride table as idx_table_diff_store.c / idx_table_write_val16.c. */
extern s32 gAiScript_aMemory[];

/* Same 12-byte record as scan_table2_80070870.c's RecA / set_reca_flag.c. */
typedef struct {
    s16 field0; /* 0x0 */
    u8 pad[4];
    u16 flags; /* 0x6 */
    u8 pad2[4];
} RecA;

extern RecA gDuel_aActiveCards[];

/* Looks up gDuel_aActiveCards[gAiScript_aMemory[idx1]] and classifies it: 0 if field0 is
   zero, 2 if flags bit 0x1000 is set, else 1. Stores the result at
   gAiScript_aMemory[idx2]. */
void AiScript_SetFaceDown(void) {
    s32 *table = gAiScript_aMemory;
    s32 idx1 = AiScript_ReadByte();
    s32 val1 = table[idx1];
    s32 idx2 = AiScript_ReadByte();
    s32 flagval;

    if (gDuel_aActiveCards[val1].field0 == 0) {
        flagval = 0;
    } else if (gDuel_aActiveCards[val1].flags & 0x1000) {
        flagval = 2;
    } else {
        flagval = 1;
    }

    gAiScript_aMemory[idx2] = flagval;
}
