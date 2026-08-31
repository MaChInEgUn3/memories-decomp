extern int D_801D4244[];
int func_8002827C(unsigned char*object){if(*(unsigned short*)(object+0x16)&0x200){int*table=D_801D4244;int index=*(short*)(object+0xC)-1;return(table[index]>>18)&15;}else{int*table=D_801D4244;int index=*(short*)(object+0xC)-1;return(table[index]>>22)&15;}}
