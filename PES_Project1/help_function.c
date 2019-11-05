//help_function.c 
//function to contain help descriptions 
//Tyler Maydew and Vignesh Iyer
//GCC compiler
//Created 9/23/2018
//ECEN 5813
//

#include <help_function.h>

struct commands
{
    char command[20];
    int8_t command_number;
    char *definition;
};

int8_t help_function (char *help_call)
{
    const char *welcome = "Welcome to ECEN5813 Project 1: Playing with Memory\n\
                           \r\n\
                           \rHere is a list of available commands:\n\
                           \rallocate,\n\
                           \rfree,\n\
                           \rdisplay,\n\
                           \rwrite,\n\
                           \rinvert,\n\
                           \rp_write,\n\
                           \rp_verify\n\
                           \n\
                           \rfor detailed help about a specific command type:\n\
                           \rhelp [command]\n\
                           \rOtherwise please enter a command.\n\
                           \rtype: exit       to escape\n";

    const char *error_msg = "\rNot a valid command\n";                           

    const commands dictionary[DICTIONARY_SIZE] =
       {
        {"help", 0, NULL},
        {"exit", 1, NULL},
        {"allocate", 2, "\r\nFORMAT: allocate #. Where # is number of 32-bit words to allocate. 0 < # < (SYSTEM DEPENDANT)\n"},
        {"free", 3, "\r\nFORMAT: free. This command frees unused allocated memory\n"},
        {"display", 4, "\r\nFORMAT: display (ADDRESS), (NUM_WORDS). Displays memory at specified ADDRESS in HEX. User can specify number of 32bit words to display.\n"},
        {"write", 5, "\r\nFORMAT: write (ADDRESS) (VALUE). User specifies 32 bit address and 32 bit value in unsigned HEX format to be written to memory\n"},
        {"invert", 6, "\r\nFORMAT: invert (ADDRESS) (NUM_WORDS). User specifies 32 bit address and 32 bit words to XOR invert. Will print speed of operation as well\n"},
        {"p_write", 7, "\r\nFORMAT: p_write (ADDRESS) (NUM_WORDS) (SEED). User specifies 32bit hex address and number of words to write pseudo-random data with seed from user. Will display speed of operation\n"},
        {"p_verify", 8, "\r\nFORMAT: p_verify (ADDRESS) (NUM_WORDS). User specifies 32 bit hex address and number of words to verify with pseudo-random pattern with user seed. Results will be printed, along with speed of operation\n"}
       };

    int8_t dictionary_entry = 0;
    
    //null ptr check
    if(!help_call){
        printf("%s\n",welcome);
        return -1;
    }
    

    dictionary_entry = comparison(dictionary, help_call);
    if(dictionary_entry < 0)
        {
            printf("%s\n\n", error_msg);
            printf("%s\n", welcome);
            printf("*********************************************\n\n");
        }
    else if(dictionary_entry == 0)
        {
            printf("%s\n", welcome);
            printf("*********************************************\n\n");
        }
    else
        printf("%s\n", dictionary[dictionary_entry].definition);

    return 0;
}
