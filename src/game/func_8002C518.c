#include "../types.h"

extern u8 D_801D0000[];
extern s32 func_8002C4DC(s32 a0);

/* Same D_801D0000[a0+591] byte test as test_byte_flag_591.c (sibling
   function at 0x8002C570), but here a clear flag falls back to looking
   up the id in find_index_in_id_table() (func_8002C4DC) instead of
   just returning -1: if the flag byte is set, return 1; otherwise
   return find_index_in_id_table(a0)'s result directly. Passing a0
   through unchanged (rather than declaring the callee `(void)`) is
   what lets gcc leave the parameter register untouched by the address
   computation -- keeping it live for the call is what puts the table
   address in a fresh $v0 instead of reusing $a0. */
int func_8002C518(int a0) {
    int flag;
    flag = (D_801D0000[a0 + 591] != 0) ? 1 : -1;
    if (flag < 0) {
        return func_8002C4DC(a0);
    }
    return 1;
}
