/* A program that has a function that gives the following
pattern:

***************
*************
***********
*********
*******
*****
***
*

*/

#include <stdio.h>

void printTri (int row);

int main (void)
{
    int row;

    printf ("\n\tPlease enter height/number of rows: ");
    scanf ("%d", &row);

    printTri (row);

    return 0;
}//main


void printTri (int row)
{
    for (int i = row; i >= 1; i--)
    {
        printf ("\n\t");

        for (int j = 1; j <= (1 + ((i - 1) * 2)); j++)
            printf ("*");
    }

    printf ("\n");

    return ;
}//prinTri

