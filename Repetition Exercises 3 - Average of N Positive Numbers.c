/* A program that prompts the user to enter an integer, n,
and then n floating-point numbers. As the numbers are read,
the program will calculate the average of the positive
numbers.  */

#include <stdio.h>

int main (void)
{
    int n;
    int nposi = 0;
    float num;
    float sum = 0;
    float ave;

    printf ("\n\tPlease enter an integer: ");
    scanf ("%d", &n);
    printf ("\tPlease enter %d floating-point numbers: ", n);

    for (int i = 1; i <= n; i++)
    {
        scanf ("%f", &num);
        if (num > 0)
        {
            sum += num;
            nposi++;
        }
    }

    if (nposi > 0)
    {
        ave = sum / nposi;
        printf ("\n\tThe average of the given positive numbers is %.2f\n", ave);
    }

    else
        printf ("\n\tThere are no positive numbers.\n");

    return 0;
}
