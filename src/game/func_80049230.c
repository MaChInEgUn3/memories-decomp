#include "../types.h"
#include "sound.h"

typedef struct {
    u8 type;
    u8 pad1;
    short value;
    int pad4;
    int data;
    u8 padC[0x24];
} Entry;

extern void func_80049010(void);
extern void func_80049138(short, int);
extern void func_80045BE8(Entry *);

void func_80049230(int value, int data)
{
    Entry entry;
    short small = value;
    if (small < 0) {
        func_80049010();
        return;
    }
    if (*g_SDValue->music_track != (small >> 4))
        func_80049138(small, 1);
    entry.type = 0x48;
    entry.value = value;
    entry.data = (short)data;
    func_80045BE8(&entry);
    g_SDValue->field_1582 = data;
    g_SDValue->field_1584 = 255;
}
