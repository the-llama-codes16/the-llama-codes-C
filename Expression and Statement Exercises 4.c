/* A program that extracts and prints the second
rightmost digit of the integral portion of a float */

#include<stdio.h>

int main(void)
{
    float numberf;
    int numberi, remainder, srdigit;

    printf("Enter a floating-point number: ");
    scanf("%f", &numberf);

    //typecasting floating-point number to integral
    numberi = (int)(numberf);

    //finding rightmost digit
    remainder = numberi%100;
    srdigit = remainder/10;

    printf("\nThe second rightmost digit of the integral portion of %f is %d.", numberf, srdigit);

    return 0;
}
