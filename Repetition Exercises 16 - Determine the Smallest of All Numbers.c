/* A program that determines the smallest of the numbers
entered by user but instead of setting the initial value
of smallest to INT_MAX, use the first number instead. */

#include <stdio.h>

int findSmallest (void);

int main (void)
{
    int smallest;

    smallest = findSmallest ();

    printf ("\n\tThe smallest number is %d.\n", smallest);

    return 0;
}//main


int findSmallest (void)
{
    int numIn, smallest;

    printf ("\n\tThis program determines the smallest of the numbers you enter.");
    printf ("\n\tPlease enter <Ctrl+D> to stop.");

    printf ("\n\tEnter number: ");
    scanf ("%d", &numIn);
    smallest = numIn;
    printf ("\tEnter another number: ");

    while (scanf ("%d", &numIn) == 1)
    {
        if (numIn < smallest)
            smallest = numIn;

        printf ("\tEnter another number: ");
    }

    return smallest;
}//findSmallest
