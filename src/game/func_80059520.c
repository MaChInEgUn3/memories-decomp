#include "../types.h"

typedef struct { unsigned char pad[0xDC0]; unsigned char bytes[8]; unsigned char tail[0x58]; } Entry;
extern Entry D_800F2C40[];
void *func_80059520(int index){Entry*e=&D_800F2C40[index];int mod=e->bytes[7]%6;unsigned char*p=e->bytes;if(mod!=0&&p[3]==0)p+=4;return p;}
