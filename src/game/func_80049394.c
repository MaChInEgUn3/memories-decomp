#include "../types.h"
#include "sound.h"

extern void func_80049010(void);

void func_80049394(void *entry)
{
    func_80049010();
    if (entry != 0)
        g_SDValue->music_track = entry;
    else
        g_SDValue->music_track = (u16 *)0x801EA800;
    *g_SDValue->music_track = 0xFFFF;
}
