/* A program that has a frequency array and will also display
the data in a histogram. The program asks data within a specified
range from the user and will do a frequency array on the input.
There is one element reserved for any number that is not within
the desired range. The frequency of such numbers out of range
will be displayed in the histogram. */

#include <stdio.h>

#define MAXDATA 50

void getData (int numData, int userData [numData]);
void getFreq (int frequency [], int numData, int userData [numData]);
void printData (int frequency [], int numData, int userData [numData]);

int main (void) {
    int frequency [22] = {0};
    int numData;

    printf ("\nThis program will print out a histogram for the data you enter.");
    printf ("\nPlease enter the number of elements you wish to provide (up to %d): ", MAXDATA);
    scanf ("%d", &numData);
    if (numData > MAXDATA) { numData = MAXDATA; }

    int userData [numData];

    getData (numData, userData);
    getFreq (frequency, numData, userData);
    printData (frequency, numData, userData);

    return;
}//main


void getData (int numData, int userData [numData]) {
    printf ("\nPlease enter %d elements that are in the range 0 - 20: \n", numData);

    for (int ctr = 0; ctr < numData; ctr++) {
        printf ("Element %d out of %d: ", ctr + 1, numData);
        scanf ("%d", &userData [ctr]);
   }

   return ;
}//getData


void getFreq (int frequency [], int numData, int userData [numData]) {
    for (int ctr = 0; ctr < numData; ctr++) {
        if (userData [ctr] >=0 && userData [ctr] <= 20) {
            frequency [userData [ctr]] += 1;
        }
        else {
            frequency [21] += 1;
        }
    }

    return;
}//getFreq


void printData (int frequency [], int numData, int userData [numData]) {
    printf ("\nThe data you entered: \n");
    for (int ctr = 0 ; ctr < numData; ctr++) {
        printf ("%4d ", userData [ctr]);
    }

    printf ("\nHistogram of values entered: \n");
    for (int ctr = 0; ctr < 22; ctr++) {
        if (ctr < 21) {
            printf ("       %2d       | ", ctr);
        }
        else {
            printf ("Not within range| ");
        }

        for (int num = 1; num <= frequency [ctr]; num++) {
            printf ("*");
        }
        printf ("\n");
    }

   return ;
}//printData
