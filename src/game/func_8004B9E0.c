#include "../types.h"
#include "sound.h"

extern void SD_ProcessSequenceTracks(void);
extern void func_8004C84C(void);
extern void func_8004AAFC(void);

void func_8004B9E0(void)
{
    if (D_8009B458->flag_0501)
        return;
    D_8009B458->flag_0501 = 1;
    if (D_8009B458->flag_0502) {
        SD_ProcessSequenceTracks();
        SD_ProcessSequenceTracks();
        SD_ProcessSequenceTracks();
        SD_ProcessSequenceTracks();
        SD_ProcessSequenceTracks();
        SD_ProcessSequenceTracks();
        SD_ProcessSequenceTracks();
        SD_ProcessSequenceTracks();
        SD_ProcessSequenceTracks();
        SD_ProcessSequenceTracks();
    }
    func_8004C84C();
    func_8004AAFC();
    D_8009B458->flag_0501 = 0;
}
