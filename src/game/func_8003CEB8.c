typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

/* CRC-16/XMODEM (poly 0x1021, zero-initialized) over data[0..len). */
u32 func_8003CEB8(u8 *data, s32 len) {
    u16 crc = 0;
    s32 i;
    i = 0;
    if (len > 0) {
        do {
            s32 bit;
            crc ^= data[i] << 8;
            for (bit = 0; bit < 8; bit++) {
                if (crc & 0x8000) {
                    crc = (crc << 1) ^ 0x1021;
                } else {
                    crc = crc << 1;
                }
            }
            i++;
        } while (i < len);
    }
    return crc;
}
