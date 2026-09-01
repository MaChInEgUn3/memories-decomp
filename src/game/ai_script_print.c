#include "../types.h"

extern int AiScript_ReadByte(void);
extern int func_8008E870(const char *, ...);
extern const char D_80011908[];
extern const char D_80011918[];

void AiScript_Print(void)
{
    int checkpoint = AiScript_ReadByte();

    func_8008E870(D_80011908);
    func_8008E870(D_80011918, checkpoint);
}
