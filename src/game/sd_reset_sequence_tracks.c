#include "../types.h"

typedef struct {
    s32 value;
    u8 pad_04[0x20];
    u8 flag;
    u8 pad_25[7];
} SequenceTrack;

typedef struct {
    u8 pad_000[0x518];
    SequenceTrack tracks[16];
    u8 pad_7D8[0x22];
    u16 track_count;
} SequenceState;

extern SequenceState *D_8009B458;

void SD_ResetSequenceTracks(void) {
    s32 i;

    for (i = 0; i < D_8009B458->track_count; i++) {
        D_8009B458->tracks[i].flag = 1;
        D_8009B458->tracks[i].value = 0;
    }
}
