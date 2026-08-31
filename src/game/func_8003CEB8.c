typedef unsigned char u8;typedef unsigned short u16;
u16 func_8003CEB8(u8*p,int len){int crc=0,i,j;__asm__ volatile("" : "+r"(crc));for(i=0;i<len;i++){crc^=p[i]<<8;for(j=7;j>=0;j--){if(crc&0x8000)crc=(crc<<1)^0x1021;else crc<<=1;}}return crc;}
