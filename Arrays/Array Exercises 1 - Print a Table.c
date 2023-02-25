/* A program that writes an array in the following format:

 0   1   1   1   1   1
-1   0   1   1   1   1
-1  -1   0   1   1   1
-1  -1  -1   0   1   1
-1  -1  -1  -1   0   1
-1  -1  -1  -1  -1   0

*/

#include <stdio.h>

int main (void)
{
    int table [6][6];

    //write data
    for (int row = 0; row < 6; row++)
    {
        for (int col = 0; col < 6; col++)
        {
            if (row == col)
                table [row][col] = 0;
            else if (row < col)
                table [row][col] = 1;
            else if (row > col)
                table [row][col] = -1;
        }
    }

    //print table
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
            printf ("%3d ", table [i][j]);

        printf ("\n");
    }

    printf ("\n\n");

    return 0;
}
