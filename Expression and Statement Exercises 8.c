/* A program that accepts temperature in Fahrenheit and
prints out the equivalent temperature in Centigrade */

#include<stdio.h>

int main(void)
{
    float cent, fah;
    float factor = 5.0/9;

    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fah);
    printf("You entered: %f", fah);

    cent = (fah-32) * factor;
    printf("\nThe equivalent temperature in Centigrade is %f", cent);

    return 0;
}
