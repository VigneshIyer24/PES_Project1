/************************************************************************************
 *
 * @file p_verify.h
 * @brief verifies pattern residing in memory
 *
 * This header file provides the function prototype
 *
 * @author Tyler Maydew
 * @date September 23 2018
 * @version 1.0
 *
 *
 */

#ifndef __P_VERIFY_H__
#define __P_VERIFY_H__

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#include <random_gen.h>
#include <wait_for_yes.h>

/*
 * verifies pattern written by p_write given a memory starting point and seed
*/

uint8_t p_verify(uint32_t **, uint64_t, uint32_t, uint32_t, uint32_t, int8_t);
#endif /* __P_VERIFY_H__ */ 
