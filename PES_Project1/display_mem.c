//display_mem.c
//displays specified memory address
//Tyler Maydew
//GCC compiler
//Created 10/1/2018
//ECEN 5813
//
//

#include <display_mem.h>

uint8_t display_mem(uint32_t **mem_block, uint64_t requested_address, uint32_t num_bytes, uint32_t num_bytes_to_display, int8_t easy_addressing)
{
    //the following code checks for invalid conditions of null ptrs, 0 byte assigned, or a non byte address
    uint8_t check_less, check_greater;
    uint32_t address_bytes;
    char dummy_check, terminator;

    char *warning = "WARNING: address was not allocated by program. Proceed with caution.\n Writing a non-allocated address will likly cause a seg fault.\n type 'y' and hit enter to proceed otherwise type any other character.\n";

    if(!easy_addressing){    
        if(!mem_block || num_bytes == 0) return -1;
        if(0 != (requested_address % 8))
        {
            printf("ERROR: Address not BYTE format\n");
            return -1;
        }
        /////////
        //the following code checks if the user is writing inside the allocated address space 
        check_less = (requested_address < (uint64_t) &(*mem_block)); //check if requested address is less than
        check_greater = (requested_address > (uint64_t) (&(*mem_block)+(num_bytes-1)));
        address_bytes = (requested_address - (uint64_t) &(*mem_block))/8; //number of bytes to add to address
        if(check_less || check_greater || ((num_bytes_to_display + address_bytes) > num_bytes)){
            printf("%s\n", warning);
            if(wait_for_yes() != 'y') return -1;
        }
    }else{
        check_less = (requested_address < 0);
        check_greater = (requested_address > ((uint64_t) (&(*mem_block)+(num_bytes-1)) - (uint64_t) (&(*mem_block))));
        address_bytes = requested_address;
        if(check_less || check_greater || ((num_bytes_to_display + address_bytes > num_bytes)))
        {
            printf("%s\n", warning);
            if(wait_for_yes() != 'y') return -1;
        }
    }
    
    uint32_t i;
    uint32_t *temp_ptr;
    temp_ptr = *mem_block + address_bytes;
    for(i = 0; i < (num_bytes_to_display); i++){
        printf("ADDR: %#lx, DATA: %#x\n", (uint64_t) &(*mem_block)+(address_bytes+ i)*8, *temp_ptr);
        temp_ptr++;
    }
    return 0;
}
