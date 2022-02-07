/* A program that has a function that creates the following
pattern, given the height (number of rows):

*
***
*****
*******
*********
*********
*******
*****
***
*

*/


#include <stdio.h>

void printPat (int row);

int main (void)
{
    int row;

    printf ("Please enter number of rows: ");
    scanf ("%d", &row);

    printPat (row);

    return 0;
}//main


void printPat (int row)
{
    for (int i = 1; i <= row; i++)
    {
        printf ("\n\t");

        for (int j = 1; j <= (1 + ((i - 1) * 2)); j++)
            printf ("*");
    }

    for (int k = row; k >= 1; k--)
    {
        printf ("\n\t");

        for (int m = 1; m <= (1 + ((k -1) * 2)); m++)
            printf ("*");
    }

    printf ("\n");
}//printPat



