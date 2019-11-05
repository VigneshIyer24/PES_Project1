/************************************************************************************
 *
 * @file parse_function.h
 * @brief parses input string and passes to specific function.
 *
 * This header file provides the function prototype
 *
 * @author Tyler Maydew
 * @date September 23 2018
 * @version 1.0
 *
 *
 */
#ifndef __PARSE_FUNCTION_H__
#define __PARSE_FUNCTION_H__

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//parse function uses all other functions
#include <help_function.h>
#include <comparison.h>
#include <allocate.h>
#include <free_mem.h>
#include <random_gen.h>
#include <write_mem.h>
#include <display_mem.h>
#include <p_write.h>
#include <p_verify.h>
#include <invert.h>
#include <wait_for_yes.h>

/*
 * takes in string from command line and parses into different sizes
 * places into appropriate functions
 *
*/


int8_t parse_function(int8_t); //command line parser

#endif /* __PARSE_FUNCTION_H__ */ 
