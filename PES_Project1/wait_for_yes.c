//wait_for_yes.c
//waits for a 'y' or other keyword from user
////Tyler Maydew
//GCC compiler
//Created 10/1/2018
//ECEN 5813
//
//

#include <wait_for_yes.h>

char wait_for_yes(void){
    char dummy_check = getchar();
    char terminator;

    while(terminator != '\n'){
        terminator = getchar();
    }
    return dummy_check;
}
