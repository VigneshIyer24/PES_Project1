/************************************************************************************
 *
 * @file allocate.h
 * @brief Allocates set amount of memory from user
 *
 * This header file provides the function prototype
 *
 * @author Tyler Maydew
 * @date September 23 2018
 * @version 1.0
 *
 *
 */

#ifndef __ALLOCATE_H__
#define __ALLOCATE_H__

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define MIN_BYTES (0)
#define MAX_BYTES (20)
/*
 *
 *returns a pointer to beginning of an allocated memory
 *that the user sets the size of
*/

uint32_t *allocate(uint32_t);
#endif /* __ALLOCATE_H__ */
