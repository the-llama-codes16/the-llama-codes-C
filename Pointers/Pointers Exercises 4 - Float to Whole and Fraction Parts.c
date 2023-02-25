/* A function that receives a floating point number
and sends back the integer and fraction parts. */

#include <stdio.h>

void split (float input, int* whole, float* decimal);

int main (void) {
    float input;
    int whole;
    float decimal;

    printf ("\nThis program receives a decimal number and returns the integer and fraction parts.");
    printf ("\nPlease enter a floating-point number: ");
    scanf ("%f", &input);

    split (input, &whole, &decimal);

    printf ("\nInput:   %7.3f", input);
    printf ("\nWhole:   %3d", whole);
    printf ("\nDecimal: %7.3f\n", decimal);

    return 0;
}//main

void split (float input, int* whole, float* decimal) {
    *whole = (int) input;
    *decimal = input - *whole;

    return ;
}//split
