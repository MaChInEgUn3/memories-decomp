#include "../types.h"

typedef struct {
    unsigned char data[24];
} DiscFile;

extern int func_8007D3F0(DiscFile *, const char *);
extern int func_8007E710(DiscFile *);

void File_GetPosition(int *output, const char *path)
{
    DiscFile file;

    while (func_8007D3F0(&file, path) == 0) {
    }
    *output = func_8007E710(&file);
}
