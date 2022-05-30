/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.h
 * @brief header of stats.c
 *
 * 
 *
 * @author Danny Wu
 * @date May/23/2022
 *
 */
#include <stdint.h>

#ifndef __STATS_H__
#define __STATS_H__

void print_statistics(uint8_t minimum, uint8_t maximum, uint8_t mean, uint8_t median, uint8_t array_lenghth);

/**
 * @brief print out all statistics of an array
 *
 * @param minimum - min value of array
 * @param maximum - max value of array
 * @param mean - mean value of array 
 * @param median - median value of array 
 * @param array_lenghth - length of array
 *
 * @return nothing
 */

void print_array(unsigned char *array, int array_lenghth); 

/**
 * @brief print all elements of array
 *
 * @param array - input array
 * @param array_lenghth - length of array
*
 * @return nothing
 */

uint8_t find_median(unsigned char *array, int array_lenghth); 

/**
 * @brief find median value of array
 *
 * @param array - input array
 * @param array_lenghth - length of array
*
 * @return median value
 */

uint8_t find_mean(unsigned char *array, int array_lenghth); 

/**
 * @brief find mean value of array
 *
 * @param array - input array
 * @param array_lenghth - length of array
*
 * @return mean value
 */

uint8_t find_maximum(unsigned char *array, int array_lenghth); 

/**
 * @brief find max value of array
 *
 * @param array - input array
 * @param array_lenghth - length of array
*
 * @return max value
 */

uint8_t find_minimum(unsigned char *array, int array_lenghth); 

/**
 * @brief find min value of array
 *
 * @param array - input array
 * @param array_lenghth - length of array
*
 * @return min value
 */

void sort_array(unsigned char *array, int array_lenghth); 

/**
 * @brief sorts the array from largest to smallest
 *
 * @param array - input array
 * @param array_lenghth - length of array
*
 * @return sorted array
 */


#endif /* __STATS_H__ */
