typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;


extern u8 gAiScript_State[], D_800EAE88[], gAiScript_aMemory[];
extern void func_8008E360(void *, s32);
void AiScript_Init(void *arg0) {
    func_8008E360(gAiScript_State, 0xD4);
    func_8008E360(D_800EAE88, 0xC);
    func_8008E360(gAiScript_aMemory, 0x50);
    if (arg0 == 0) gAiScript_State[0] = 1;
    *(void **)(gAiScript_State + 4) = arg0;
    *(void **)(gAiScript_State + 8) = arg0;
}
