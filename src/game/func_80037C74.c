#include "../types.h"

int func_80037C74(unsigned char *object) {
    if (*(short *)(object + 0x38) >= *(short *)(object + 0x3E)) {
        *(short *)(object + 0x38) = 0;
        *(unsigned short *)(object + 0x3A) += object[0x5B];
    }
    if (*(short *)(object + 0x42) < *(short *)(object + 0x3A) + object[0x5B]) {
        *(unsigned short *)(object + 0x3A) -= object[0x5B];
        return 1;
    }
    return 0;
}
