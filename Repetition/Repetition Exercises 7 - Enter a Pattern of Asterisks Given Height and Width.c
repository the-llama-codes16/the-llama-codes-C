/* A function that creates the following pattern,
given the height (number of rows) and the width
(asterisks per row):

*********************
*********************
*********************

*/

#include <stdio.h>

int main (void)
{
    int row, asterisk;

    printf ("\n\tEnter height/number of rows: ");
    scanf ("%d", &row);
    printf ("\tEnter width/number of asterisks per row: ");
    scanf ("%d", &asterisk);


    for (int i = 1; i <= row; i++)
    {
        printf ("\n\t");

        for (int j = 1; j <= asterisk; j++)
            printf ("*");
    }

    printf ("\n");

    return 0;
}
