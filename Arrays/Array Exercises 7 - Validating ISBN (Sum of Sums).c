/* A program that validates an ISBN (International Standard Book Number)
using the sum of sums method.

Sample ISBN:
0 - 07 - 881809 - 5

DIGIT       SUM OF DIGITS       SUM OF SUMS
0                 0                  0
0                 0                  0
7                 7                  7
8                 15                 22
8                 23                 45
1                 24                 69
8                 32                 101
0                 32                 133
9                 41                 174
5                 46                 220
                            --------------
                            220 % 11 = 0 (VALID)

*/

#include <stdio.h>
#include <stdbool.h>

void getData (int ISBN []);
void sum (int ISBN []);

int main (void)
{
    int ISBN [10];

    printf ("\n\tThis program determines if an ISBN is valid using Sum of Sums Method.\n");
    getData (ISBN);
    sum (ISBN);
    sum (ISBN);

    printf ("\n\t");
    for (int i = 0; i < 10; i++)
        printf ("%4d ", ISBN[i]);
    printf ("\n");

    printf ("\n\tThe ISBN provided is valid: ");
    if (!(ISBN [9] % 11))
        printf ("Yes\n");
    else
        printf ("No\n");

    return 0;
}//main


void getData (int ISBN [])
{
    for (int i = 0; i < 9; i++)
    {
        printf ("\tPlease enter digit %d of 10: ", i + 1);
        scanf ("%d", &ISBN[i]);
    }

    printf ("\tPlease enter digit 10 of 10: (10 if X) ");
    scanf ("%d", &ISBN[9]);

    return ;
}//getData


void sum (int ISBN [])
{
    for (int i = 0; i < 10; i++)
        ISBN [i + 1] = ISBN [i] + ISBN [i + 1];

    return ;
}//sum

