/* A program that extracts and prints the
rightmost digit of the integral portion of a float */

#include<stdio.h>

int main(void)
{
    float numberf;
    int numberi, rdigit;

    printf("Enter a floating-point number: ");
    scanf("%f", &numberf);

    //typecasting floating-point number to integral
    numberi = (int)(numberf);

    //finding rightmost digit
    rdigit = numberi%10;

    printf("\nThe rightmost digit of the integral portion of %f is %d.", numberf, rdigit);

    return 0;
}
