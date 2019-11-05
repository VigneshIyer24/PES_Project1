
//comparison.c
//compares two strings in a dictionary and returns index
//Tyler Maydew and Vignesh Iyer
//GCC compiler
//Created 9/23/2018
//ECEN 5813
//
//
//

#include <comparison.h>


int8_t comparison(const commands dictionary[], char *help_call)
{
    int8_t i = 0;
    for(i = 0; i < DICTIONARY_SIZE; ++i)
    {
        if(strncmp(dictionary[i].command, help_call, 4) == 0)
            return i;
    }
    return -1;
}

