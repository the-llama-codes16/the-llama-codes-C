/* A program that prompts the user to enter an integer n,
and then n floating-point numbers. As the numbers are
read, the program will calculate the average of the
negative numbers. */

#include <stdio.h>

int main (void)
{
    int n;
    int nnega = 0;
    float num;
    float sum = 0;
    float ave;

    printf ("\n\tPlease enter an integer: ");
    scanf ("%d", &n);
    printf ("\tPlease enter %d floating-point numbers: ", n);

    for (int i = 1; i <= n; i++)
    {
        scanf ("%f", &num);
        if (num < 0)
        {
            sum += num;
            nnega++;
        }
    }

    if (nnega > 0)
    {
        ave = sum / nnega;
        printf ("\n\tThe average of the given negative numbers is %.2f\n", ave);
    }

    else
        printf ("\n\tThere are no negative numbers.\n");

    return 0;
}
