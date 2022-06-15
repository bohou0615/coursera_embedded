#include <stdio.h>
#include <stdint.h>
#include "data.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){

    uint8_t size = 12;
    uint8_t tempArray[size];
    uint8_t isNegative = 0;
    uint8_t strLength = 0;
    uint8_t myChar = 0;

    if (data == 0){
        *ptr = '0';
        *(ptr+1) = 0;
        return 2;
    }
    if (data<0){
        data = data*-1;
        isNegative = 1;
    }

    tempArray[strLength] = 0x0;
    strLength++;

    while (data >= 1){
        myChar = data%base;

        if(myChar>=0 && myChar<=9){
            tempArray[strLength] = myChar + 0x30;
        }

        if(myChar>=10 && myChar<=15){
            tempArray[strLength] = myChar + 0x37;
        }

        data = data/base;
        strLength++;
    }
     if(isNegative){
        tempArray[strLength] = '-';
        strLength++;
    }

    for(uint8_t i=0 ; i<strLength; i++){
        *(ptr+i)=tempArray[strLength-1-i];
    }


    return strLength;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
    
    uint32_t number=0;
	uint8_t isNegative = 0;

    if(*ptr == '-'){
        isNegative = 1;
        digits--;
        ptr++;
    }
    
    digits--;

	for(int i = 0; i < digits; i++)
	{
	    number = number * base + *ptr - '0';
	    ptr++;
	}

	if(isNegative)
	{
	    number = -number;
	}

	  return number;
}