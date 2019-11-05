/************************************************************************************
 *
 * @file p_write.h
 * @brief fills indicated memory spaces with a randomly defined pattern
 *
 * This header file provides the function prototype
 *
 * @author Tyler Maydew
 * @date September 23 2018
 * @version 1.0
 *
 *
 */

#ifndef __P_WRITE_H__
#define __P_WRITE_H__

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#include <random_gen.h>
#include <wait_for_yes.h>

/*
 * given a memory address to start at, psuedo random numbers are filled per user
 * request using custom random function.
*/

uint8_t p_write(uint32_t **, uint64_t, uint32_t, uint32_t, uint32_t, int8_t);
#endif /* __P_WRITE_H__ */ 
