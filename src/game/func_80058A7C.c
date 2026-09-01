#include "../types.h"

typedef struct{unsigned short h0,h2,h4,h6,h8,hA,hC,hE,h10;short h12;int h14,h18;}Params;unsigned int func_80058A7C(int side,int mode,Params*p){register int offset;unsigned int hi,lo;side&=1;offset=side<<8;p->h4-=0x280;p->h4+=offset;if(p->h12<0x100){p->h10-=0x80;if(p->h12==8)p->h12=side+0xF2;}else{p->h10-=0x280;p->h10+=offset;}hi=((p->h0&3)<<7)|((mode&3)<<5)|(((p->h6&0x100)<<16)>>20)|((p->h4&0x3ff)>>6)|((p->h6&0x200)<<2);lo=(*(unsigned short*)&p->h12<<6)|((p->h10>>4)&0x3f);return (hi<<16)|(lo&0xffff);}
