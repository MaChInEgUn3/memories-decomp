extern void SD_SEPlay(unsigned int, int, int);

void SD_SEPlayFull(unsigned int value)
{
    SD_SEPlay(value & 0xFFFF, 0xFF, 0);
}
