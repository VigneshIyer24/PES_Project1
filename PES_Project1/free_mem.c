//free.c
//frees memory allocated
//Tyler Maydew
//GCC compiler
//Created 09/29/2018
//ECEN 5813
//
//

#include <free_mem.h>

uint8_t free_mem(uint32_t *mem_block_begin){
    free(mem_block_begin);
    return 0;    
}
