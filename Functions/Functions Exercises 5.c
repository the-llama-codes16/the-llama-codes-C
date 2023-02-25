/* A program that has a user-define function that converts
inches into centimeters */

#include<stdio.h>

float inToCm(float in);

int main(void)
{
    float in,cm;

    printf("Enter measurement in inches: ");
    scanf("%f", &in);

    cm = inToCm(in);
    printf("The equivalent measurement in centimeters is %.2f\n\n", cm);

    return 0;
}

//*****inToCm******
float inToCm(float in)
{
    return (in*2.54);
}
