/* A program that performs the following if variable "flag"
is true:

a. read integer variables a and b
b. calculate and print the sum and average of inputs */

#include <stdio.h>

int main (void)
{
    char flag;
    int a, b;

    printf ("Flag: (Write t for true and f for false) ");
    scanf (" %c", &flag);
    flag = tolower (flag);

    if (flag != 0)
        {
            int sum;
            float ave;

            printf ("\na: ");
            scanf ("%d", &a);
            printf ("\nb: ");
            scanf ("%d", &b);

            sum = a + b;
            ave = sum / 2.0;

            printf ("\nSum: %d", sum);
            printf ("\nAverage: %.2f\n", ave);
        }

    return 0;
}
