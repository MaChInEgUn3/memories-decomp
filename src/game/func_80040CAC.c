typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;

typedef void (*ObjFn)(u8 *);
typedef struct {
    u8 pad0[2];
    s16 unk2;
    u8 pad4[0x20];
    ObjFn unk24;
    u8 pad28[0x48];
} Slot70;

extern s16 D_800EFE38;
extern Slot70 D_800EFE48[];

void func_80040CAC(void)
{
    s32 i = D_800EFE38;

    while (i >= 0) {
        Slot70 *p = &D_800EFE48[i];
        ObjFn f = p->unk24;
        i = p->unk2;
        if (f != 0) {
            f((u8 *)p);
        }
    }
}
