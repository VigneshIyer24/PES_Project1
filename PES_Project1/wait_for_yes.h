/************************************************************************************
 *
 * @file wait_for_yes.h
 * @brief waits for a char from user 
 *
 * This header file provides the function prototype
 *
 * @author Tyler Maydew
 * @date September 23 2018
 * @version 1.0
 *
 *
 */

#ifndef __WAIT_FOR_YES_H__
#define __WAIT_FOR_YES_H__

#include <stdint.h>
#include <stdio.h>

/*
 * given a memory address to start at, psuedo random numbers are filled per user
 * request using custom random function.
*/

char wait_for_yes(void);
#endif /* __WAIT_FOR_YES_H__ */ 
