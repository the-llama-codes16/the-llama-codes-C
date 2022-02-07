/* A program that reads an integer from the keyboard
and then calls a recursive function to print it out
in reverse. For example, if the user enters 4762,
it prints 2674. */

#include <stdio.h>

void printRev (int num);

int main (void)
{
    int num;

    printf ("\n\tThis program prints out the number you enter in reverse.");
    printf ("\n\tExample: 4762 -> 2674");
    printf ("\n\tPlease enter a number: ");
    scanf ("%d", &num);
    printf ("\t");

    printRev (num);

    printf ("\n");

    return 0;
}//main


void printRev (int num)
{
    int rev;

    if (num == 0)
        return;
    else
    {
        rev = num % 10;
        printf ("%d", rev);
        num = num / 10;
    }

    printRev (num);
}//printRev
