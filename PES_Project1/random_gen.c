#include <random_gen.h>

uint32_t random_gen(uint32_t seed)
{
    uint32_t Xn;
    int8_t count;
    //uint32_t num_ran = 0;
    uint32_t A, C, M;
    A = CONSTANT_A;
    C = CONSTANT_C;
    M = CONSTANT_M;

    Xn = seed;
	
    for(count=0;count<100;count++)
	{
		Xn=((Xn*A)+C)%M;
        //num_ran = (Xn*sizeof(u_int32_t));
	}
	return Xn;
}



