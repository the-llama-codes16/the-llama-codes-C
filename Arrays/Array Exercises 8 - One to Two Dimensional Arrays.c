/* A program that has a function that copies
a one-dimensional array of n elements into a
two-dimensional array of k rows and j columns.
The rows and columns must be a valid factor
of the number of elements in the one-dimensional
array; that is, k * j = n. */

#include <stdio.h>

void getData (int* n, int* k, int* j);
void getDataOne (int n, int oneArray [n]);
void oneToTwo (int k, int j, int twoArray [k][j], int n, int oneArray [n]);

int main (void)
{
    int n;
    int k, j;

    getData (&n, &k, &j);

    //elements for one-dimensional array
    int oneArray [n];
    getDataOne (n, oneArray);

    //transforming one-dimensional array to two-dimensional array
    int twoArray [k][j];
    oneToTwo (k, j, twoArray, n, oneArray);

    return 0;
}//main


void getData (int* n, int* k, int* j)
{
    printf ("\n\tThis program will transform a one-dimensional array of N elements");
    printf ("\n\tto a two-dimensional array of K and J elements.");

    do
    {
        printf ("\n\tPlease enter value of N: ");
        scanf ("%d", n);
        printf ("\tPlease enter values of K and J: (NOTE: K and J must be factors of N) ");
        scanf ("%d %d", k, j);
    }while (*k * *j != *n);

    return ;
}//getData


void getDataOne (int n, int oneArray [n])
{
    printf ("\n\tPlease enter the elements of the one-dimensional array: \n");

    for (int i = 0; i < n; i++)
    {
        printf ("\tEnter element %d of %d: ", i + 1, n);
        scanf ("%d", &oneArray[i]);
    }

    printf ("\n\tYour input is:\n\t");
    for (int i = 0; i < n; i++)
        printf ("%4d ", oneArray [i]);

    return ;
}//getDataOne


void oneToTwo (int k, int j, int twoArray[k][j], int n, int oneArray [n])
{
   int oneIndex = 0;

   for (int row = 0; row < k; row ++)
   {
        for (int col = 0; col < j; col++)
        {
            twoArray [row][col] = oneArray [oneIndex];
            oneIndex++;
        }
   }

   printf ("\n\tThe Transformed Array is: \n\t");
    for (int row = 0; row < k; row++)
    {
        for (int col = 0; col < j; col++)
        {
            printf ("%4d ", twoArray [row][col]);
        }

        printf ("\n\t");
    }

    printf ("\n");

   return ;
}//oneToTwo



