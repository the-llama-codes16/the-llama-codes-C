/* A program containing a modified sort algorithm
for two parallel arrays. The sort will only sort
the identifier, but each corresponding data for each
identifier will also sort accordingly.

Example:

ID      SCORE
1       72
2       89
3       98
4       105

Use the following data for testing:
18      90
237     47
35      105
5       25
76      739
103     26
189     38
22      110
156     31
49      245

PSEUDOCODE
declare arrays for identifiers and corresponding scores
ask user for number of data
call function to receive input from user
    pre array for identifier, array for scores
    post void
call function to sort identifiers
    pre array for identifier, array for scores
    post void
call function to print result
    pre array for identifier, array for scores
    post void

*/

#include <stdio.h>

void getData (int numData, int identifiers [numData], int scores [numData]);
void sortData (int numData, int identifiers [numData], int scores [numData]);
void printData (int numData, int identifiers [numData], int scores [numData]);

int main (void) {
    int numData;

    printf ("\nThis program will sort two parallel arrays.");
    printf ("\nInput number of pairs (up to 50): ");
    scanf ("%d", &numData);
    if (numData > 50){
        numData = 50; }

    int identifiers [numData];
    int scores [numData];

    getData (numData, identifiers, scores);
    sortData (numData, identifiers, scores);
    printData (numData, identifiers, scores);

    return 0;
}//main


void getData (int numData, int identifiers [numData], int scores [numData]) {
    for (int ctr = 0; ctr < numData; ctr++) {
        printf ("\nSet %d of %d: \nID: ", ctr + 1, numData);
        scanf ("%d", &identifiers [ctr]);
        printf ("Score: ");
        scanf ("%d", &scores [ctr]);
    }

    return ;
}//getData


void sortData (int numData, int identifiers [numData], int scores [numData]) {
    int pass  = numData - 1;
    int smallest;
    int temp;

    for (int ctr = 0; ctr < pass; ctr++) {
        smallest = ctr;
        for (int walk = ctr + 1; walk <= pass; walk++) {
            if (identifiers [smallest] > identifiers [walk]) {
                smallest = walk; }
        }
        if (smallest != ctr) {
            temp = identifiers [smallest];
            identifiers [smallest] = identifiers [ctr];
            identifiers [ctr] = temp;

            temp = scores [smallest];
            scores [smallest] = scores [ctr];
            scores [ctr] = temp;
        }
    }

    return ;
}//sortData


void printData (int numData, int identifiers [numData], int scores [numData]) {
    printf ("\nID        SCORE\n");
    for (int ctr = 0; ctr < numData; ctr++) {
        printf ("%3d       %5d\n", identifiers [ctr], scores [ctr]);
    }

    return ;
}//printData
