#pragma once
#include<stdio.h>
#include<math.h>
#include <stdlib.h>

/*
    Prints a double with 4 fraction precision
    $$Params$$
        number : number to print
*/
void print_float_test(double number);


void print_float_test(double number)
{
    double integral;
    double fractional = modf(number, &integral);
    fractional = fractional<0 ? fractional*(-1) : fractional;
    printf("%d.%d ", (unsigned int)integral, (unsigned int)(fractional*10000));
}
