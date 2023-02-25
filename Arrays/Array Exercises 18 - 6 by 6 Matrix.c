/* A program that writes the following six-by-six matrix :

1   1   1   1   1   0
1   1   1   1   0  -1
1   1   1   0  -1  -1
1   1   0  -1  -1  -1
1   0  -1  -1  -1  -1
0  -1  -1  -1  -1  -1

*/

#include <stdio.h>

#define ROW 6
#define COL 6

void writeMatrix (int matrix [][COL]);
void printMatrix (int matrix [][COL]);

int main (void) {
    int matrix [ROW][COL];

    writeMatrix (matrix);
    printMatrix (matrix);

    return 0;
}//main


void writeMatrix (int matrix [][COL]) {
    int diagonal;
    int element;

    for (int row = 0; row < ROW; row++) {
        for (int col = 0; col < COL; col++) {
            diagonal = COL - 1 - row;

            if (col < diagonal) {
                element = 1; }
            else if (col == diagonal) {
                element = 0; }
            else if (col > diagonal) {
                element = -1; }

            matrix [row][col] = element;
        }
    }

    return ;
}//writeMatrix


void printMatrix (int matrix [][COL]) {
    for (int row = 0; row < ROW; row++) {
        for (int col = 0; col < COL; col++) {
            printf ("%4d ", matrix [row][col]);
        }
        printf ("\n");
    }

    return ;
}//printMatrix

