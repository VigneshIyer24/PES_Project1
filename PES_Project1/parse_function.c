//parse_function.c
//parse file for project 1
//Tyler Maydew and Vignesh Iyer
//GCC compiler
//Created 09/23/2018
//ECEN 5813
//


#include <parse_function.h>


int8_t parse_function(int8_t easy_addressing)
{
    char string_buffer[100]; //character array to use string token
    char *check;
    char *end_of_string; 
    char *ptr; //toss ptr;
    int8_t dictionary_entry;
    uint32_t num_bytes; 
    char *function_call = (char *) malloc(100);
    uint32_t *mem_block_begin, data, num_bits, seed;
    uint64_t address;
    uint8_t allocated = 0, display_success, write_success;
	
    struct function_2
    {
	    char parsed_line[20];
    };
    
    struct timespec start_time,end_time;
    if(!function_call){
        printf("MALFORMED INPUT\n");
        return -1;
    }

    
    commands number[9] =
       {
        {"help", 0, NULL},
        {"exit", 1, NULL},
        {"allocate", 2, NULL},
        {"free", 3, NULL},
        {"display", 4, NULL},
        {"write", 5, NULL},
        {"invert", 6, NULL}, 
        {"p_write", 7, NULL}, 
        {"p_verify", 8, NULL} 
       };
    
    char *dummy_light = "\rWARNING: Memory does not appear to be allocated. Function will likely fail. 'y' to proceed.\n";

    uint8_t stop = 0;

    while(stop != 2){
        //above structure contains the 7 help commands
        stop = 0;
        printf("\r\n****************************\n");
        printf("\rEnter Command:\n");
        fgets(function_call, 100, stdin);
        strcpy(string_buffer, function_call); //copies input string into character array
        //printf("string_buffer = %s\n", string_buffer); 
        //
        
        struct function_2 string_tokens[4]; //declare an array of character pointers
        check = strtok(string_buffer," "); //reads in the first word in the string
        int32_t i=0;
        
        while(check != NULL){
            //printf("string: %s and i: %d\n", check, i);
            if(i > 4){
                continue;
            }else{
                strcpy(string_tokens[i].parsed_line,check);
            }
            //printf("sizeof string_tokens[%i] = %lu\n", i, sizeof(string_tokens[i].parsed_line));
            i++;
            check = strtok(0," ");
            //printf("check = %s\n", check);
        }
        
        dictionary_entry = comparison(number, string_tokens[0].parsed_line);
        
        address = (uint64_t) strtol(string_tokens[1].parsed_line, &ptr, (easy_addressing) ? 10: 16);
        data = (uint32_t) strtol(string_tokens[2].parsed_line, &ptr, 16);
        num_bits = (uint32_t) strtol(string_tokens[2].parsed_line, &ptr, 10);
        seed = (uint32_t) strtol(string_tokens[3].parsed_line, &ptr, 16);
        

        switch (dictionary_entry)
        {
            case 0:  //help
                {
                    if(strncmp(string_tokens[1].parsed_line, " ", 2) <= 10)
                    {
                        help_function("help");
                    }else{
                        help_function(string_tokens[1].parsed_line);
                    }
                    break;
                }
            
            case 1: //exit
                {
                    stop = 2;
                    break;
                }
           
            case 2: //allocate
                {
                    if(allocated)
                    {
                        printf("\rERROR: Memory already allocated. Proceed at own risk. Hit 'y' and enter to cont.\n");
                        printf("\rPreviously allocated memory will be inaccessible. \n");
                        //put in continue dummy function
                        if(wait_for_yes() == 'y') mem_block_begin = allocate(num_bytes); //return 1 indicates that we have allocated memory 
                    }else
                    {
                        num_bytes = (uint32_t) strtol(string_tokens[1].parsed_line, &ptr, 10);
                        mem_block_begin = allocate(num_bytes);
                        if(!mem_block_begin){
                            allocated = 0;
                            printf("\rExceeded maximum malloc size. Please try again.\n");
                        }else{
                            printf("\rADDRs ASSIGNED START:\n");
                            printf("\rADDR: %p\n", (&mem_block_begin));
                            allocated = 1;
                        }
                    } 
                    break;
                }

            case 3: //free
                {
                    if(allocated){
                        allocated = free_mem(mem_block_begin);
                        printf("\rMemory FREED successfully!\n");                        
                    }
                    else{
                        printf("\r%s\n", dummy_light);
                        if(wait_for_yes() == 'y') allocated = free_mem(mem_block_begin); //return 1 indicates that we have allocated memory 
                    }
                    break;
                }

            case 4: //display
                {
                    if(allocated){
                        display_success = display_mem(&mem_block_begin, address, num_bytes, num_bits, easy_addressing);
                    }else{
                        printf("\r%s\n", dummy_light);
                        if(wait_for_yes() == 'y') display_success = display_mem(&mem_block_begin, address, num_bytes, num_bits, easy_addressing);
                    }
                    break;
                }

            case 5: //write
                {
                    if(allocated){
                        write_success = write_mem(&mem_block_begin, address, data, num_bytes, easy_addressing); 
                    }else{
                        printf("\r%s\n", dummy_light);
                        if(wait_for_yes() == 'y') write_success = write_mem(&mem_block_begin, address, data, num_bytes, easy_addressing); 
                    }
                    break;
                }

            case 6: //invert
                {
                    if(allocated){
                        write_success = invert(&mem_block_begin, address, num_bytes, num_bits, easy_addressing);
                    }else{
                        printf("\r%s\n", dummy_light);
                        if(wait_for_yes() == 'y') write_success = invert(&mem_block_begin, address, num_bytes, num_bits, easy_addressing);
                    }
                    break;
                }

            case 7: //write pattern
                {
                    if(allocated){
                        write_success = p_write(&mem_block_begin, address, num_bytes, num_bits, seed, easy_addressing);
                    }else{
                        printf("\r%s\n", dummy_light);
                        if(wait_for_yes() == 'y') write_success = p_write(&mem_block_begin, address, num_bytes, num_bits, seed, easy_addressing);
                    }
                    break;
                } 

            case 8: //verify pattern
                {
                    if(allocated){
                        display_success = p_verify(&mem_block_begin, address, num_bytes, num_bits, seed, easy_addressing);
                    }else{
                        printf("\r%s\n", dummy_light);
                        if(wait_for_yes() == 'y') display_success = p_verify(&mem_block_begin, address, num_bytes, num_bits, seed, easy_addressing);
                    }
                    break;
                }
            
            default:
                {
                    printf("\rNot a valid input. Type help for assistance\n");
                }
        }
    }

    free(function_call);
    return 0;
}

