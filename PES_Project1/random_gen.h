/************************************************************************************
 *
 * @file random_gen.h
 * @brief frees allocated memory
 *
 * This header file provides the function prototype
 *
 * @author Tyler Maydew and Vignesh Iyer
 * @date Oct 1 2018
 * @version 1.0
 *
 *
 */

#ifndef __RANDOM_GEN_H__
#define __RANDOM_GEN_H__

#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#define CONSTANT_A (1103515245)
//a is the multiplier value and if carefully picked can generate seemingly random values.
//This value is used in gcc rand() and thus is appropraite. More detailed explanation is
//in the documentation
#define CONSTANT_M (2147483647)
//M is the range of numbers and 2,147,483,647 is the largest decimal number we can use
#define CONSTANT_C (12345678)
//a constant value that will adjust the value by incrementing. Chosen arbitrarily, but
//like a, carefully chosen c will help give more random numbers.
//
//RosettaCode.org helped explain the functionality and give equations to be implemented

/*
 * Generates a pseudo-random number using the linear congruential
 * generator method, similar to gcc random
*/

uint32_t random_gen(uint32_t);
#endif /* __RANDOM_GEN_H__ */ 
