typedef unsigned char u8;typedef signed char s8;typedef unsigned short u16;
void func_800384E4(u8*object){register u8*obj asm("$5");register u8**stream asm("$3");register u8*current asm("$2");register unsigned int value asm("$4");obj=object;*(u16*)(obj+0x34)&=0xEFFF;stream=&((u8**)obj)[*(s8*)(obj+0x58)];current=*stream;value=*current;current++;*stream=current;if(value)*(u16*)(obj+0x34)|=0x1000;}
