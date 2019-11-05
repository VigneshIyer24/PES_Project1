//allocate.c
//memory allocation program
//Tyler Maydew
//GCC compiler
//Created 09/23/2018
//ECEN 5813
//
//

#include <allocate.h>

uint32_t *allocate(uint32_t num_bytes)
{
    uint32_t *block_beginning;
    
    if(/*(num_bytes > MAX_BYTES) ||*/ (num_bytes <= MIN_BYTES))
    {
        printf("ERROR: Bytes requested outside allowed range. Please type help allocate\n");
        return NULL;
    }
    
    block_beginning = (uint32_t *)malloc(num_bytes*sizeof(uint32_t));
    return block_beginning;
}
