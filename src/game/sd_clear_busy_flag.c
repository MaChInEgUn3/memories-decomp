#include "../types.h"
#include "sound.h"

void SD_ClearBusyFlag(void)
{
    g_SDValue->busy = 0;
}
