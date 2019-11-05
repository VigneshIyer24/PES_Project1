/************************************************************************************
 *
 * @file comparison.h
 * @brief compares two strings using strncmp 
 *
 * This header file provides the function prototype
 *
 * @author Tyler Maydew
 * @date September 23 2018
 * @version 1.0
 *
 *
 */

#ifndef __COMPARISON_H__
#define __COMPARISON_H__


#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define DICTIONARY_SIZE (9)
/*
 * compares two string values to check for equality to a certain number of chars
 *
*/

typedef const struct
{
    char command[20];
    int8_t command_number;
    char *definition;
} commands;

int8_t comparison(const commands *, char *);
#endif /* __COMPARISON_H__ */
