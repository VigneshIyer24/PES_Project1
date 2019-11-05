/************************************************************************************
 *
 * @file free_mem.h
 * @brief frees allocated memory
 *
 * This header file provides the function prototype
 *
 * @author Tyler Maydew
 * @date September 23 2018
 * @version 1.0
 *
 *
 */
#ifndef __FREE_MEM_H__
#define __FREE_MEM_H__

#include <stdint.h>
#include <stdlib.h>

/*
 * frees allocated block of memory using free()
 *
*/

uint8_t free_mem(uint32_t *);
#endif /* __FREE_MEM_H__ */ 
