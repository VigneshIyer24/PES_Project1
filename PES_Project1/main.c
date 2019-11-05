//main.c 
//primary file for project 1
//Tyler Maydew and Vignesh Iyer
//GCC compiler
//Created 9/23/2018
//ECEN 5813
//

#include <parse_function.h>

int8_t main(void) {
    int8_t stop = 0;
    char easy_addressing;
    char stop_long_typer = 'q';
    
    help_function(NULL); 
    
    printf("Before we get started, would you like to use easy addressing?\n\
\rInstead of typing the full address provided by the system,   \n\
\ryou will instead type an offset.                             \n\
\rIf this sounds ideal please type 'y' and enter otherwise hit any key to\n\
\rcontinue as normal. NOTE: This cannot be changed midprogram\n");

    easy_addressing = getchar();
    while(stop_long_typer != '\n'){
        stop_long_typer = getchar();
    }
    if(easy_addressing == 'y'){
        stop = parse_function(1);
    }else{
        stop = parse_function(0);
    }
    printf("\r\nTHANKS FOR USING! BYE\n");
    return 0;
}


