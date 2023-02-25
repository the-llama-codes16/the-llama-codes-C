/* A program that reads two integer from the keyboard,
multiplies them, and then prints the two numbers and
their product.*/

#include<stdio.h>

int main(void)
{
    int a,b,product;

    printf("Enter first number: ");
    scanf("%d", &a);

    printf("Enter second number: ");
    scanf("%d", &b);

    product = a*b;

    printf("\nThe product of %d and %d is %d.", a,b,product);

    return 0;
}
