/* A program that accepts values for a two-dimensional
array then puts the averages of each rows and columns in
2 one-dimensional arrays.

PSEUDOCODE

declare arrays
call getData func
    pre: 2-dimensional array
    post: void
    for loop to write data
print table to check (debugging)
call rowAve func
    pre: 2-dimensional array, one-dimensional array for each row ave
    post: void
    for loop through each row
        for loop to sum
call rowCol func
    pre: 2-dimensional array
    post: one-dimensional array for each col ave
    for loop through each col
        for loop to sum
call printData func:
    pre: all arrays
    post: void
    for loop to display data
*/

#include <stdio.h>

#define MAX_ROWS 5
#define MAX_COLS 6

void getData (int userData [][MAX_COLS]);
void rowCalc (int userData [][MAX_COLS], float rowAve []);
void colCalc (int userData [][MAX_COLS], float colAve []);
void printRes (int userData [][MAX_COLS], float rowAve [], float colAve []);

int main (void)
{
    int userData [MAX_ROWS][MAX_COLS];
    float rowAve [MAX_ROWS] = {0};
    float colAve [MAX_COLS] = {0};

    getData (userData);
    rowCalc (userData, rowAve);
    colCalc (userData, colAve);

    printRes (userData, rowAve, colAve);

    return 0;
}//main


void getData (int userData [][MAX_COLS])
{
    for (int c = 0; c < MAX_ROWS; c++)
    {
        for (int d = 0; d < MAX_COLS; d++)
        {
            printf ("Enter Data: ");
            scanf ("%d", &userData[c][d]);
        }
    }

    return ;
}//getData


void rowCalc (int userData [][MAX_COLS], float rowAve [])
{
    int sum;
    float ave;

    for (int c = 0; c < MAX_ROWS; c++)
    {
        sum = 0;

        for (int d = 0; d < MAX_COLS; d++)
        {
            sum += userData[c][d];
        }

        ave = (sum * 1.0) / MAX_COLS;
        rowAve[c] = ave;
    }

    return ;
}//rowCalc


void colCalc (int userData [][MAX_COLS], float colAve [])
{
    int sum;
    float ave;

    for (int i = 0; i < MAX_COLS; i++)
    {
        sum = 0;

        for (int j = 0; j < MAX_ROWS; j++)
        {
            sum += userData[j][i];
        }

        ave = (sum * 1.0) / MAX_ROWS;
        colAve[i] = ave;

    }

    return ;
}//colCalc


void printRes (int userData [][MAX_COLS], float rowAve [], float colAve [])
{
    //print table and rowAve
    printf ("\n");
    for (int a = 0; a < MAX_ROWS; a++)
    {
        for (int b = 0; b < MAX_COLS; b++)
        {
            printf ("%5d   ", userData[a][b]);
        }
        printf ("|  %5.2f\n", rowAve[a]);
    }

     //print colAve
    printf ("\n");
    printf ("-------------------------------------------------\n");
    for (int k = 0; k < MAX_COLS; k++)
    {
        printf ("%5.2f   ", colAve[k]);
    }
    printf ("\n");

    return ;
}//printRes

