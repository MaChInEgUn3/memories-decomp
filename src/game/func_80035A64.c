#include "../types.h"

typedef struct {
    unsigned char pad[0x28];
    int first, second, third;
    short fourth;
    unsigned char rest[0x2E];
} Entry;
extern Entry D_800EB0F8[];
extern void DuelEffect_ResetOccupancy(void), DuelEffect_ResetEntryMarkers(void);
void func_80035A64(void) {
    int i = 4;
    Entry *entry = D_800EB0F8;
    __asm__ volatile("" : "+r"(entry));
    do {
        entry->fourth = 0;
        entry->third = 0;
        entry->second = 0;
        entry->first = 0;
        __asm__ volatile("" ::: "memory");
        i--;
        entry++;
    } while (i != 0);
    DuelEffect_ResetOccupancy();
    DuelEffect_ResetEntryMarkers();
}
