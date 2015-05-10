#include <stdlib.h>
#include <libpic30.h>
#include <math.h>
#include "../inc/globals.h"


int ADRaw;
double ADValue,ADAverage,ADTest;
BYTE_VAL Flags;
//int __C30_UART;
void InitGlobals(void)
{
    ADRaw = 0;
    ADValue = 0.0;
    ADTest = 0.0;
    Flags.Val = 0;

    //__C30_UART = 1;

    return;
}

void dtoa(double dnumber, char *str)
{
    int integer = 0,i = 0;
    char temp[5];
    float mantissa;

    integer = (int)dnumber; //Get the integer part of the float
    mantissa = dnumber - (double)integer; //Get the decimal part of the float

    strcpy(temp, itoa(str, integer, 10)); //
    i = sizeof(temp) - 1;
    
    //printf("%d\r\n", i);

    str[i] = '.';

    mantissa = mantissa * pow(10, 5);
    itoa(str + i + 1, (int)mantissa, 10);

    return;
}
