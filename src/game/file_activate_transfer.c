#include "../types.h"

typedef struct {
    s32 value[18];
} Block72;

typedef struct {
    s32 value[8];
} Block32;

extern u8 D_800E9E60[];
extern u8 D_800E9E18[];
extern u8 D_801D4200[];
extern u16 D_8009B112;
extern s32 D_8009B0F4;

void File_ActivateTransfer(void) {
    *(Block72 *)D_800E9E60 = *(Block72 *)D_800E9E18;
    *(Block32 *)D_801D4200 = *(Block32 *)(D_801D4200 + 32);
    if (D_800E9E60[70] == 4)
        D_8009B112 |= 1;
    D_8009B0F4 = *(s32 *)(D_800E9E60 + 44) | 16;
}
