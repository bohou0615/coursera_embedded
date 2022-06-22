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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "memory.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){
    // Create pointers to the pointers


    if(dst == src) return dst;

    if (dst < src){
        while (length--){
            *dst++= *src++;
        }
    }
    else{
        src = src + (length-1);    
        dst = dst + (length-1);    
        while (length--){
            *dst-- = *src--;
        }
    }
    return dst;
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){

    while (length){
        length--;
        *dst++ = *src++;
    }
    return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){

    while (length){
        length--;
        *src++ = value;
    }
    return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length){
    return my_memset(src, length, 0);
}

uint8_t * my_reverse(uint8_t * src, size_t length){
    
    uint8_t *temp;
    temp = (uint8_t*)malloc(length*sizeof(uint8_t)); 
    if(! temp){
        printf("ERROR: allocating dynamic memory for my_reverse function call\n");
    }
    uint8_t *lastTemp = temp+length; 
    for(int i=0; i<length; i++){
        *(temp+i)=*(src+i);
    }

    while(length--){
        *(src+length)= *(lastTemp-length-1);
    }
    free(temp);
    return src;
}

int32_t * reserve_words(size_t length){
    return malloc(length*sizeof(length));
}

void free_words(uint32_t * src){
    free(src);
}