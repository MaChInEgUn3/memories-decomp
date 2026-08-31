typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;

typedef struct Object {
    u8 pad0[4];
    u32 flags;
    u16 flags2;
    u8 padA[0x1A];
    void (*callback)(struct Object *);
    s16 timer;
    s16 angle;
    s16 baseX;
    s16 baseY;
    s16 x;
    s16 y;
    u8 pad34[0xC];
    s16 depth;
    u8 pad42[0x1E];
    s16 duration;
    u8 pad62[6];
    u8 color0;
    u8 color1;
    u8 pad6A[2];
    u8 active;
} Object;

extern u32 D_8009B0CC;
extern u8 D_801AF000[];
extern void *func_8004002C(void);
extern Object *func_800400AC(void *, int);
extern void func_800428A8(Object *, int, int, int, int, int, int, int, void *);
extern void func_800428EC(Object *, int);
extern void func_80042BC0(Object *);
extern int func_80086770(int);
extern int func_800866A0(int);

void func_80020D4C(Object *object)
{
    register Object *spawned __asm__("$16");
    register Object *self __asm__("$17") = object;
    int value;

    self->timer -= 2;
    if (self->timer <= 0) {
        *(u32 *)&self->x = *(u32 *)&self->baseX;
        self->active = 0;
        self->callback = 0;
        return;
    }

    if (D_8009B0CC & 1) {
        spawned = func_800400AC(func_8004002C(), 2);
        if (spawned != 0) {
            func_800428A8(spawned, self->x, self->y, 0,
                          self->color0, self->color1, 0x11, 9, D_801AF000);
            spawned->depth = self->depth + 0x80;
            spawned->flags2 |= 0x28;
            spawned->flags |= 0x50000000;
            func_800428EC(spawned, (s8)(self->pad0[0x16] - 1));
            spawned->duration = 8;
            spawned->callback = func_80042BC0;
        }
    }

    self->angle += 0x30;
    value = func_80086770(self->angle);
    self->x = self->baseX + (value * self->timer) / 0x1000;
    value = func_800866A0(self->angle);
    self->y = self->baseY + (value * self->timer) / 0x1000;
}
