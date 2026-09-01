typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

extern int AiScript_ReadShort(void);
extern s32 AiScript_ReadByte(void);
extern s32 func_8008E590(void);

/* Same 4-byte-stride table as idx_table_diff_store.c / idx_table_write_val16.c. */
extern s32 gAiScript_aMemory[];

/* Reads a [lo, hi] bound pair from the byte stream (func_800705AC),
   picks a table slot (func_8007058C), then stores a value from
   rand folded into [lo, hi] via modulo. */
void AiScript_SetRandom(void) {
    s32 lo = AiScript_ReadShort();
    s32 hi = AiScript_ReadShort();
    s32 idx = AiScript_ReadByte();

    gAiScript_aMemory[idx] = func_8008E590() % (hi - lo + 1) + lo;
}
