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
 * @file main.c
 * @final Assessment
 *
 * @author Danny Wu
 * @date May 15 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



int main(void) {
  #ifdef COURSE1
  printf("calling course1()\n");
  course1();
  #endif
}

