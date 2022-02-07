/* A program that has a function that creates the
following pattern, given the height (number of rows)
and the width (print characters per line)

=====================
*                   *
*                   *
*                   *
*                   *
*                   *
*                   *
*                   *
=====================

*/

#include <stdio.h>

void printPattern (int row, int character);

int main (void)
{
    int row, character;

    printf ("\n\tEnter height/number of rows: ");
    scanf ("%d", &row);
    printf ("\tEnter width/print characters per line: ");
    scanf ("%d", &character);

    printPattern (row, character);

    return 0;
}//main


void printPattern (int row, int character)
{

    for (int j = 1; j <= row + 2; j++)
    {
        if (j == 1 || j == row + 2)
        {
            printf ("\n\t");

            for (int i = 1; i <= character; i++)
                printf ("=");
        }

        else
        {
            printf ("\n\t*");

            for (int k = 1; k <= character - 2; k++)
                printf (" ");

            printf ("*");
        }
    }

    return ;
}//printPattern
