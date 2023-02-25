/* Rewriting Program 6-26 using an iterative solution

Program 6-26: A program that prints out the Fibonacci series
using a recursive function.

0 1 1 2 3 5 8 13
*/

#include <stdio.h>

void printFibo (int n);

int main (void)
{
    int n;

    printf ("\n\tThis program will print out the Fibonacci series.");
    printf ("\n\tHow many terms do you want? ");
    scanf ("%d", &n);

    printFibo (n);

    return 0;
}//main


void printFibo (int n)
{
    long int a = 0;
    long int b = 1;
    long int c;

    if (n < 2)
        printf ("\n\t%8ld", a);
    else if (n == 2)
        printf ("\n\t%8ld,%8ld", a, b);
    else
    {
        printf ("\n\t%8ld,%8ld,", a, b);

        for (int i = 3; i <= n; i++)
            {
            c = a + b;

            if (i % 5 == 0)
                printf ("%8ld\n\t", c);
            else
                printf ("%8ld,", c);

            a = b;
            b = c;
            }
    }

    printf ("\n");
    return ;
}//printFibo
