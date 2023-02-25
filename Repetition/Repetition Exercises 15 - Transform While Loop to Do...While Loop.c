/* Rewrite Program 6-19 (in book) from a while loop
to a do...while loop.

Program 6-19:
A program that reads a series of numbers, terminated by EOF,
and return their sum to the calling program

*/

#include <stdio.h>

int readSum (void);

int main (void)
{
    int sum;

    printf ("\n\tThis program will return the sum of the numbers you enter. <Ctrl+D> to stop\n");
    sum = readSum ();

    printf ("\tSum: %d\n", sum);
    return 0;
}//main


int readSum (void)
{
    int sum = 0;
    int num;
    int ioResult;

    do
    {
        printf ("\tEnter a number: ");
        ioResult = scanf ("%d", &num);
        sum += num;
    } while (ioResult == 1);

    return sum;
}//readSum
