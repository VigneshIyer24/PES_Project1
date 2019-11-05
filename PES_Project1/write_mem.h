/************************************************************************************
 *
 * @file write_mem.h
 * @brief writes spec'd address with 32 bits
 *
 * This header file provides the function prototype
 *
 * @author Tyler Maydew
 * @date September 23 2018
 * @version 1.0
 *
 *
 */
#ifndef __WRITE_MEM_H__
#define __WRITE_MEM_H__

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <wait_for_yes.h>
/*
 * given a memory address the function writes given data
*/

uint8_t write_mem(uint32_t **, uint64_t, uint32_t,  uint32_t, int8_t);
#endif /* __WRITE_MEM_H__ */ 
