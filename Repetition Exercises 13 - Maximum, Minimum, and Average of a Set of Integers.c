/* A program that reads integer data from the standard
input unit and prints the minimum integer read, maximum
integer read, and the average of the list. */

#include <stdio.h>
#include <limits.h>

int main (void)
{
    int num;
    float sum = 0;
    float ave = 0;
    int counter = 0;
    int largest = INT_MIN;
    int smallest = INT_MAX;

    printf ("\n\tEnter integers: <Ctrl + D> to exit\n\t");

    while (scanf ("%d", &num) == 1)
    {
        sum += num;
        counter++;

        if (num > largest)
            largest = num;

        if (num < smallest)
            smallest = num;
    }

    ave = sum / counter;

    printf ("\n\tMinimum Integer Read: % 4d", smallest);
    printf ("\n\tMaximum Integer Read: % 4d", largest);
    printf ("\n\tAverage: %.2f\n", ave);

    return 0;

}
