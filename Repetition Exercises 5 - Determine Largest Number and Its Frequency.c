/* A program that asks the user to enter a list of
integers. The program is to determine the largest
value entered and the number of times it was entered.
For example, if the following series is entered

    5 2 15 3 7 15 8 9 5 2 15 3 7

It would output the largest value is 15 and it was
entered 3 times.
*/


#include <stdio.h>
#include <limits.h>

int main (void)
{
    int repeat = 0;
    int num = 0;
    int largest = INT_MIN;

    printf ("\n\tPlease enter a series of numbers: <Enter + Ctrl+D + Enter> to stop. ");

    while (scanf ("%d", &num) == 1)
    {
        if (num > largest)
        {
            largest = num;
            repeat = 1;
        }

        else if (num == largest)
            repeat++;
    }

    printf ("\n\tThe largest value is %d and it was entered %d time/s.\n", largest, repeat);

    return 0;
}
