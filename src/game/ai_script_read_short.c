#include "../types.h"

/* Same byte-stream cursor as stream_read_advance.c. */
struct Stream {
    u8 pad[8];
    u8 *cursor;
};

extern struct Stream gAiScript_State;

/* Reads a little-endian 16-bit value from the stream and advances the
   cursor by 2. */
int AiScript_ReadShort(void) {
    u8 *p = gAiScript_State.cursor;
    gAiScript_State.cursor += 2;
    return p[0] | (p[1] << 8);
}
