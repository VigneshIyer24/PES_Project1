//write_mem.c
//writes specified memory address
//Tyler Maydew
//GCC compiler
//Created 09/23/2018
//ECEN 5813
//
//

#include <write_mem.h>

uint8_t write_mem(uint32_t **mem_block, uint64_t requested_address, uint32_t write_data,  uint32_t num_bytes, int8_t easy_addressing){

    uint8_t check_less, check_greater;
    uint32_t address_bytes;
    char dummy_check, terminator;

    char *warning = "WARNING: address was not allocated by program. Proceed with caution.\n\
                    Writing a non-allocated address will likly cause a seg fault.\n type 'y'and hit enter to proceed otherwise type any other character.\n";

    //the following code checks for invalid conditions of null ptrs, 0 byte assigned, or a non byte address
    if(!mem_block || num_bytes == 0) return -1;
    /////////
    if(!easy_addressing){
        //the following code checks if the user is writing inside the allocated address space 
        if(0 != (requested_address % 8))
        {
            printf("ERROR: Address not BYTE format\n");
            return -1;
        }
        check_less = (requested_address < (uint64_t) &(*mem_block)); //check if requested address is less than
        check_greater = (requested_address > (uint64_t) (&(*mem_block)+(num_bytes-1)));
        
        if(check_less || check_greater)
        {
            printf("%s\n", warning);
            if(wait_for_yes() != 'y') return -1;
        }
        //if the user proceeds a seg fault will likely occur
        //determine which byte to address and assign data appropriately
        address_bytes = (requested_address - (uint64_t) &(*mem_block))/8; //number of bytes to add to address
    }else{
        check_less = (requested_address < 0);
        check_greater = (requested_address > ((uint64_t) (&(*mem_block)+(num_bytes-1)) - (uint64_t) (&(*mem_block))));
        if(check_less || check_greater)
        {
            printf("%s\n", warning);
            if(wait_for_yes() != 'y') return -1;
        }
        address_bytes = requested_address;
    }
    uint32_t *temp_ptr;
    temp_ptr = *mem_block + address_bytes;
    *temp_ptr = write_data;
   
    printf("ADDR: %#lx, DATA: %#x  <<< Written\n", (uint64_t) &(*mem_block) + 8*address_bytes, *temp_ptr);
    return 0;
}

