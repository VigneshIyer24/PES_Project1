
/************************************************************************************
 *
 * @file help_function.h
 * @brief Prints varying help messages for the user
 *
 * This header file provides the function prototype
 *
 * @author Tyler Maydew
 * @date September 23 2018
 * @version 1.0
 *
 *
 */
#ifndef __HELP_FUNCTION_H__
#define __HELP_FUNCTION_H__

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <comparison.h>

/*
 * Searches a command dictionry to print appropriate help messages
 * for the user. Return 0 on success and -1 on a void pointer passage
 *
*/


int8_t help_function (char *help_call);
#endif /* __HELP_FUNCTION_H__ */ 
