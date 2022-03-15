/* A program that tests an ISBN to see if it is valid.

ISBN (International Standard Book Number) has:
1. 10 digits
2. A weighted sum divisible by 11, and is calculated as follows:

Sample ISBN:
0 - 07 - 881809 - 5
CODE      WEIGHT       WEIGHTED VALUE
0           10              0
0            9              0
7            8              56
8            7              56
8            6              48
1            5              5
8            4              32
0            3              0
9            2              18
5            1              5
                TOTAL ---  220
                220 % 11 = 0 (VALID)


3. The last number may be X, which means 10.
*/

#include <stdio.h>
#include <stdbool.h>

void getData (int ISBN []);
bool weightVal (int ISBN [], int weight []);

int main (void)
{
    int ISBN [10];
    int weight [10];
    bool validity;

    printf ("\n\tThis program determines if an ISBN is valid.\n");
    getData (ISBN);
    validity = weightVal (ISBN, weight);

    printf ("\n\tThe ISBN provided is valid: ");
    if (validity)
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


bool weightVal (int ISBN [], int weight [])
{
    int factor = 10;
    int sum = 0;

    for (int i = 0; i < 10; factor--, i++)
        weight [i] = ISBN [i] * factor;

    for (int i = 0; i < 10; i++)
        sum += weight [i];

    if (!(sum % 11))
        return true;
    else
        return false;
}//weightVal


