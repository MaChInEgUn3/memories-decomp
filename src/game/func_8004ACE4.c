typedef unsigned char u8;

typedef struct {
    int first;
    int second;
    short third;
    short fourth;
    u8 padC[12];
} Packet;

extern u8 *D_8009B458;
extern int func_80075DC0(void);
extern void func_80075BE0(int);
extern int func_800767E0(int);
extern void func_80076790(int);
extern void func_80075DE0(Packet *);

void func_8004ACE4(u8 *entry, int unused)
{
    Packet packet;
    switch (entry[0x11]) {
    case 0x0F:
        if (func_80075DC0() == 1)
            func_80075BE0(0);
        if (func_800767E0(-1) != 0)
            func_80076790(0);
        packet.first = 1;
        packet.second = entry[0x13];
        func_80075DE0(&packet);
        if (func_800767E0(-2) != 0)
            func_80076790(1);
        func_80075BE0(1);
        D_8009B458[0x844] = entry[0x13];
        break;
    case 0x10:
        packet.first = 6;
        packet.third = entry[0x13] << 8;
        packet.fourth = entry[0x13] << 8;
        func_80075DE0(&packet);
        func_80075BE0(1);
        D_8009B458[0x845] = entry[0x13];
        break;
    }
}
