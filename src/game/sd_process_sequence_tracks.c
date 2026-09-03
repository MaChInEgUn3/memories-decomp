#include "../types.h"

extern u8 *D_8009B458;
extern int func_8004C420(void *);
extern int func_8004BB34(void *);
extern void func_8004C5C8(void *);

int SD_ProcessSequenceTracks(void) {
    u8 *initial = D_8009B458;
    u8 *state = initial + 0x518;
    int i;
    u8 *entry;

    if (*(short *)(state + 0x2CA) != 1)
        return 0;
    if (*(u16 *)(state + 0x2E2) == 0)
        return 0;
    i = 0;
    entry = state;
loop:
    if (entry[0x24] == 0) {
        int sum = *(u16 *)(entry + 0x14) +
                  *(u16 *)(entry + 0x16);
        *(short *)(entry + 0x14) = sum;
        if ((u16)sum >= 0x100) {
            *(short *)(entry + 0x14) = (u8)sum;
            if (i == *(u16 *)(state + 0x2E0))
                (*(int *)(state + 0x2D8))++;
            {
                int count = *(int *)(entry + 0x1C);
                if (count != 0 &&
                    *(int *)(D_8009B458 + 0x80C) == 0) {
                    *(int *)(entry + 0x1C) = count - 1;
                    goto accumulate;
                }
retry:
                func_8004C420(entry);
                if (entry[0x24] == 0) {
                    int value = func_8004BB34(entry);
                    *(int *)(entry + 0x1C) = value;
                    if (value == 0)
                        goto retry;
                    if (*(int *)(D_8009B458 + 0x804) != 0)
                        func_8004C5C8(entry);
                    if (*(int *)(entry + 0x1C) == 0)
                        goto retry;
                }
                if (*(int *)(entry + 0x1C) != 0)
                    (*(int *)(entry + 0x1C))--;
            }
accumulate:
            {
                u8 *root = D_8009B458;
                int total = *(int *)(root + 0x7DC) + *(int *)entry;
                int threshold = *(int *)(root + 0x80C);
                *(int *)(root + 0x810) = total;
                if (threshold != 0 && (unsigned int)total >=
                                      (unsigned int)threshold)
                    *(int *)(root + 0x80C) = 0;
            }
        }
    }
    {
        int count = *(u16 *)(state + 0x2E2);
        i++;
        if (i < count) {
            entry += 44;
            goto loop;
        }
    }
    return 0;
}
