/* A program that accepts temperature in Centigrade and prints
out the equivalent temperature in Fahrenheit */

#include<stdio.h>

int main(void)
{
    float cent,fah;
    float factor=9.0/5;

    printf("Please enter temperature in degrees Centigrade: ");
    scanf("%f", &cent);
    printf("You entered: %f", cent);

    fah = 32+(cent*factor);
    printf("\nThe equivalent temperature in Fahrenheit is %f", fah);

    return 0;
}
