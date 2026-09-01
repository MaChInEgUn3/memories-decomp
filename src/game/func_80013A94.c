#include "../types.h"

typedef struct {
    unsigned char padding_00[0x2C];
    unsigned int flags;
    unsigned char padding_30[0x16];
    unsigned char state;
} Transfer;

extern unsigned int D_8009B0F4;
extern Transfer D_800E9E18;
extern void func_80013940(Transfer *, int, int, int);

Transfer *func_80013A94(int file_index, int sector_offset)
{
    Transfer *transfer;

    if (D_8009B0F4 & 0x20) {
        return 0;
    }

    transfer = &D_800E9E18;
    func_80013940(transfer, file_index & 0xF, sector_offset, 0);
    transfer->state = 0;
    transfer->flags = 0x00100000;
    D_8009B0F4 |= 0x20;
    return transfer;
}
