//p_verify
//verifies random pattern
////Tyler Maydew
//GCC compiler
//Created 10/1/2018
//ECEN 5813
//
//

#include <p_verify.h>

uint8_t p_verify(uint32_t **mem_block, uint64_t requested_address, uint32_t num_bytes, uint32_t num_bytes_to_display, uint32_t seed, int8_t easy_addressing){
    //clock measurement
    struct timespec start_time,end_time;
    clock_gettime(CLOCK_REALTIME,&start_time);

    uint8_t check_less, check_greater;
    uint32_t address_bytes;
    char dummy_check, terminator;

    char *warning = "WARNING: address was not allocated by program. Proceed with caution.\n Reading a non-allocated address will produce unknown values.\n type 'y' and hit enter to proceed otherwise type any other character.\n";

    if(!easy_addressing){
        //the following code checks for invalid conditions of null ptrs, 0 byte assigned, or a non byte address
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


    uint32_t i, err_cnt = 0, check_value;
    uint32_t *temp_value, previous;
    previous = random_gen(seed);
    temp_value = *mem_block + address_bytes;
    for(i = 0; i < (num_bytes_to_display); i++){
        check_value = random_gen(previous);
        if(*temp_value == check_value){
            printf("ADDR: %#lx, DATA: %#x << VERIFIED\n", (uint64_t) &(*mem_block)+(address_bytes+ i)*8, *temp_value);
        }else{
            printf("\n***FAILED***\n");
            printf("Expected: ADDR: %#lx, DATA: %#x << NOT VERIFIED\n", (uint64_t) &(*mem_block)+(address_bytes+ i)*8, check_value);
            printf("Received: ADDR: %#lx, DATA: %#x << NOT VERIFIED\n", (uint64_t) &(*mem_block)+(address_bytes+ i)*8, *temp_value);
            err_cnt++;
        }
        previous = check_value; 
        temp_value++;
    }
   
    printf("Total Memory Errors: %u\n", err_cnt);
    clock_gettime(CLOCK_REALTIME,&end_time);
	double end1=(double)end_time.tv_sec;
	double start1=(double)start_time.tv_sec;
	double end2=(double)end_time.tv_nsec;
	end2=end2/1000000000;
	double start2=(double)start_time.tv_nsec;
	start2=start2/1000000000;
	printf("Time Taken=%2.10lf s \n",((end2+end1)-(start2+start1)));
    //printf("Total time = %ld s %ld ns\n",(end_time.tv_sec-start_time.tv_sec),(end_time.tv_nsec-start_time.tv_nsec));
    return 0;

}

