typedef unsigned char u8;typedef unsigned short u16;extern void func_800393B0(void*);
void func_80039A60(u8*o){*(u16*)(o+0x34)|=0xA00;do{func_800393B0(o);}while(!(*(u16*)(o+0x34)&0x2000));}
