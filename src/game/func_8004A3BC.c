typedef unsigned char u8;

int func_8004A3BC(u8 *entry, int value)
{
    u8 check = value;
    int result;
    if (check < 64) {
        if (entry[0x11] == 0)
            return 0;
        result = -((entry[0x11] << 1) * (64 - (u8)value));
    } else {
        if (check == 64)
            return 0;
        if (entry[0x10] == 0)
            return 0;
        result = (entry[0x10] << 1) * ((u8)value - 63);
    }
    return (short)result;
}
