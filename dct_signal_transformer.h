#include <stdio.h>
#include <math.h>
#include "utils.h"

// Defines
#define SIGNAL_SIZE 512


// Prototypes

/*
    Transforms the signal via DCT
    $$Params$$
        select_n : signal length to transform
        select_m : number of DCT values to transmit to remote server
*/
void transform_signal(uint, uint);

/*
    Prints to output of M DCT values in "vector format" for matlab
    $$Params$$
        select_m : number of DCT values to print
*/
void print_m_dct_coefficients(uint select_m);


// Globals
static const double ecg_signal[] = {0.35, 0.35, 0.35, 0.35, 0.35, 0.35, 0.35, 0.35, 0.35, 0.020, -0.21, -0.33, -0.37, -0.335, -0.285, -0.23, -0.215, -0.20, -0.19, -0.20, -0.20, -0.21, -0.23, -0.25, -0.255, -0.245, -0.24, -0.215, -0.235, -0.23, -0.23, -0.205, -0.18, -0.165, -0.195, -0.21, -0.215, -0.195, -0.17, -0.155, -0.175, -0.195, -0.21, -0.20, -0.20, -0.195, -0.185, -0.185, -0.18, -0.175, -0.175, -0.165, -0.14, -0.12, -0.115, -0.13, -0.155, -0.19, -0.19, -0.185, -0.18, -0.16, -0.14, -0.13, -0.11, -0.12, -0.13, -0.13, -0.125, -0.095, -0.095, -0.090, -0.080, -0.075, -0.070, -0.075, -0.065, -0.055, -0.060, -0.055, -0.040, -0.030, -0.020, -0.015, -0.015, -0.010, 0.015, 0.035, 0.025, 0.015, 0.015, 0.025, 0.025, 0.040, 0.040, 0.030, 0.015, 0.020, 0.035, 0.045, 0.050, 0.025, 0.020, 0.020, 0.010, 0.010, 0, -0.0050, -0.025, -0.020, -0.030, -0.030, -0.035, -0.045, -0.055, -0.060, -0.065, -0.075, -0.080, -0.075, -0.075, -0.075, -0.070, -0.075, -0.080, -0.090, -0.10, -0.095, -0.095, -0.085, -0.095, -0.10, -0.10, -0.115, -0.115, -0.13, -0.14, -0.15, -0.16, -0.145, -0.155, -0.16, -0.17, -0.185, -0.175, -0.17, -0.165, -0.17, -0.17, -0.165, -0.18, -0.18, -0.20, -0.20, -0.215, -0.205, -0.21, -0.205, -0.21, -0.22, -0.225, -0.225, -0.24, -0.225, -0.21, -0.205, -0.195, -0.19, -0.20, -0.19, -0.19, -0.185, -0.17, -0.17, -0.175, -0.165, -0.165, -0.185, -0.185, -0.205, -0.205, -0.21, -0.195, -0.195, -0.19, -0.195, -0.195, -0.195, -0.185, -0.175, -0.175, -0.20, -0.225, -0.25, -0.24, -0.24, -0.24, -0.25, -0.26, -0.27, -0.28, -0.305, -0.335, -0.35, -0.34, -0.285, -0.205, -0.135, -0.095, -0.045, 0.010, 0.075, 0.14, 0.175, 0.135, 0.045, -0.155, -0.425, -0.71, -0.915, -1.09, -1.255, -1.395, -1.465, -1.505, -1.49, -1.45, -1.39, -1.34, -1.27, -1.155, -1.025, -0.95, -0.93, -0.93, -0.91, -0.885, -0.865, -0.84, -0.80, -0.755, -0.715, -0.66, -0.63, -0.58, -0.54, -0.51, -0.465, -0.435, -0.395, -0.365, -0.315, -0.265, -0.20, -0.155, -0.090, -0.040, -0.015, -0.010, 0.0050, 0.030, 0.055, 0.080, 0.085, 0.090, 0.11, 0.11, 0.13, 0.15, 0.155, 0.15, 0.18, 0.185, 0.205, 0.22, 0.235, 0.235, 0.255, 0.27, 0.29, 0.29, 0.30, 0.30, 0.305, 0.325, 0.315, 0.31, 0.315, 0.315, 0.345, 0.36, 0.37, 0.375, 0.375, 0.365, 0.375, 0.385, 0.41, 0.405, 0.40, 0.40, 0.405, 0.40, 0.41, 0.395, 0.40, 0.385, 0.39, 0.395, 0.385, 0.38, 0.355, 0.355, 0.355, 0.35, 0.325, 0.30, 0.28, 0.25, 0.25, 0.25, 0.25, 0.235, 0.21, 0.175, 0.165, 0.16, 0.145, 0.14, 0.145, 0.13, 0.10, 0.080, 0.040, 0.015, -0.010, -0.025, -0.025, -0.030, -0.040, -0.045, -0.070, -0.105, -0.080, -0.075, -0.085, -0.090, -0.11, -0.13, -0.12, -0.115, -0.125, -0.15, -0.17, -0.16, -0.16, -0.15, -0.155, -0.16, -0.17, -0.185, -0.18, -0.18, -0.19, -0.18, -0.17, -0.16, -0.14, -0.14, -0.145, -0.17, -0.18, -0.175, -0.16, -0.155, -0.155, -0.165, -0.15, -0.155, -0.15, -0.145, -0.145, -0.165, -0.195, -0.205, -0.19, -0.18, -0.165, -0.17, -0.16, -0.17, -0.165, -0.17, -0.17, -0.17, -0.17, -0.185, -0.19, -0.18, -0.18, -0.18, -0.175, -0.20, -0.21, -0.20, -0.20, -0.21, -0.215, -0.21, -0.20, -0.175, -0.16, -0.145, -0.145, -0.135, -0.14, -0.135, -0.13, -0.12, -0.115, -0.11, -0.105, -0.10, -0.095, -0.11, -0.14, -0.175, -0.18, -0.18, -0.18, -0.165, -0.175, -0.175, -0.175, -0.165, -0.165, -0.165, -0.175, -0.165, -0.16, -0.155, -0.15, -0.155, -0.16, -0.16, -0.155, -0.145, -0.15, -0.15, -0.185, -0.20, -0.20, -0.195, -0.19, -0.19, -0.195, -0.20, -0.195, -0.185, -0.175, -0.175, -0.155, -0.17, -0.17, -0.165, -0.15, -0.16, -0.165, -0.175, -0.17, -0.17, -0.185, -0.215, -0.225, -0.19, -0.125, -0.040, 0.050, 0.125, 0.215, 0.32, 0.415, 0.50, 0.605, 0.725, 0.845, 0.94, 1.06, 1.11, 1.1, 1.005, 0.86, 0.615, 0.24, -0.11, -0.335, -0.46, -0.515, -0.54, -0.51, -0.44, -0.385, -0.36, -0.35, -0.335, -0.32, -0.295, -0.30, -0.30, -0.325, -0.335, -0.335};
//static const double ecg_signal[] = {1,2,3,4,5,6,7,8};
static double dct_coefficients[SIGNAL_SIZE];


void transform_signal(uint select_n, uint select_m)
{
    uint k;
    printf("step 1 \n");
    double const_value = M_PI / select_n;
    for (k = 0; k < select_n; k++)
    {

        printf("current loop 1 %d \n", (int)k);
        dct_coefficients[k] = 0;
        uint n;
        for (n = 0; n < select_n; n++)
        {
            dct_coefficients[k] = dct_coefficients[k] + ecg_signal[n] * cos(const_value * ((n + 0.5) * k));
        }
    }
    printf("step 2 \n");
    uint i;
    for (i = select_m; i <= select_n; i++)
    {
        dct_coefficients[i] = 0;
    }
    printf("step 3 \n");
}


void print_m_dct_coefficients(uint select_n)
{
    uint i;
    printf("[");
    for (i = 0; i < select_n; i++)
    {
       print_float_test(dct_coefficients[i]);
    }
    printf("]");
    printf("\n");
}
