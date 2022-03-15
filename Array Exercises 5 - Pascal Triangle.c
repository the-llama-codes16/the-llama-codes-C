/* A program that creates a Pascal triangle of any size.

size 7:

1
1   1
1   2   1
1   3   3   1
1   4   6   4   1
1   5   10  10  5   1
1   6   15  20  15  6   1

*/

#include <stdio.h>

void pascal (int pasSize, int pasTri [][pasSize]);
void printRes (int pasSize, int pasTri [][pasSize]);

int main (void)
{
    int pasSize;

    printf ("\n\tThis program creates a Pascal triangle.");
    printf ("\n\tPlease enter the size: ");
    scanf ("%d", &pasSize);

    int pasTri [pasSize][pasSize];
    pascal (pasSize, pasTri);
    printRes (pasSize, pasTri);

    return 0;
}//main


void pascal (int pasSize, int pasTri [][pasSize])
{
    pasTri[0][0] = 1;
    pasTri[1][0] = 1;
    pasTri[1][1] = 1;

    //loop for each row
    for (int row = 2; row < pasSize; row++)
    {
        pasTri[row][0] = 1;

        //loop for each column
        for (int col = 1; col < row; col++)
            pasTri[row][col] = pasTri[row - 1][col] + pasTri[row - 1][col - 1];

        pasTri[row][row] = 1;
    }

    return ;
}//pascal


void printRes (int pasSize, int pasTri [][pasSize])
{
    for (int row = 0; row < pasSize; row++)
    {
        for (int col = 0; col <= row; col++)
            printf ("%4d ", pasTri[row][col]);

        printf ("\n");
    }

    return ;
}//printRes
