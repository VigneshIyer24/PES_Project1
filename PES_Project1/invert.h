/************************************************************************************
 *
 * @file display_mem.h
 * @brief displays spec'd address with 32 bits
 *
 * This header file provides the function prototype
 *
 * @author Tyler Maydew
 * @date September 23 2018
 * @version 1.0
 *
 *
 */
#ifndef __INVERT_H__
#define __INVERT_H__


#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#include <wait_for_yes.h>
/*
 * given a memory address the function displays given data
*/

uint8_t invert(uint32_t **, uint64_t, uint32_t, uint32_t, int8_t);
#endif /* __INVERT_H__ */ 
