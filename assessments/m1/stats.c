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
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */



#include <stdio.h>
#include <stdint.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  	unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

    uint8_t minimum;
    uint8_t maximum;
    uint8_t mean;
    uint8_t median;
    uint8_t array_lenghth;
  	sort_array(test, array_lenghth);
  	minimum = find_minimum(test, array_lenghth);
  	maximum = find_maximum(test, array_lenghth);
  	mean = find_mean(test, array_lenghth);
  	median = find_median(test, array_lenghth);
  	print_array(test, array_lenghth);
  	print_statistics(minimum, maximum, mean, median, array_lenghth);

}

/* Add other Implementation File Code Here */
void print_statistics(uint8_t minimum, uint8_t maximum, uint8_t mean, uint8_t median, uint8_t array_lenghth){
	printf("minimum value: %u\n", minimum);
  	printf("maximum value: %u\n", maximum);
  	printf("mean value: %u\n", mean);
  	printf("median value: %u\n", median);
  	printf("array length: %u\n", array_lenghth);
}

void print_array(unsigned char *array, int array_lenghth){
	
	for(int i = 0; i < array_lenghth; i++){
		printf("%u\n", array[i]);
	}

}

uint8_t find_median(unsigned char *array, int array_lenghth){
	// check if sorted
	sort_array(array, array_lenghth);

	if (array_lenghth % 2 == 1){
		return array[array_lenghth/2];
	}

	uint8_t median;
	median = (array[array_lenghth/2-1] + array[array_lenghth/2+1]) / 2;
	return median;

}

uint8_t find_mean(unsigned char *array, int array_lenghth){

	int sum = 0;

	for(int i = 0; i<array_lenghth; i++){
		sum += array[i];
	}

	return (sum/array_lenghth);
}

uint8_t find_maximum(unsigned char *array, int array_lenghth){

	uint8_t maximum;

	sort_array(array, array_lenghth);

	return array[array_lenghth-1];
}

uint8_t find_minimum(unsigned char *array, int array_lenghth){

	uint8_t maximum;

	sort_array(array, array_lenghth);

	return array[0];
}

void sort_array(unsigned char *array, int array_lenghth){

	for(int i = 0; i<array_lenghth; i++){
		for(int j = i+1; j<array_lenghth; j++){
			if(array[i] < array[j]){
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}