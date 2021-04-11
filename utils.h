#pragma once
#include<stdio.h>
#include<math.h>
#include <stdlib.h>


void print_float(float);
void print_float_test(double number);



void print_float(float number)
{
    int A;
    float frac;
    A = number;
    frac = (number - A) * 100;
    printf("%d.%02u ", A, (unsigned int)frac);
}


void print_float_test(double number)
{
    double integral;
    double fractional = modf(number, &integral);
    fractional = fractional<0 ? fractional*(-1) : fractional;
    printf("%d.%d ", (unsigned int)integral, (unsigned int)(fractional*10000));
}
