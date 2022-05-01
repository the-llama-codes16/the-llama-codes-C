/*
A program that sorts a 50-element array using the
selection sort, the bubble sort, and the insertion sort.
Each sort is to be executed twice.

a. For the first sort, fill the array with random numbers
between 1 and 1000.
b. For the second sort, fill the array with a nearly ordered
list. Create the nearly ordered list by filling the array
with sequential numbers and then subtracting 5 from every 10th
number in the array.
c. Each sort (selection, bubble, insertion) is to sort the same
data. For each sort, count the number of comparisons and moves
necessary to order this list.
d. After each sort execution, print the unsorted data followed
by the sort data in 5-by-10 matrixes (5 rows of 10 numbers each).
After the sorted data, print the number of comparisons and the
number of moves required to order the data. Provide appropriate
headings for each printout.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define COUNT 50

void genValues (int numlist []);
void copyVal (int numlist [], int sortedSel [], int sortedBub [], int sortedIns []);
void selectSort (int sortedSel []);
void bubbleSort (int sortedBub []);
void insertSort (int sortedIns []);
void newArray (int sortedSel [], int sortedBub [], int sortedIns []);

int main (void) {
    int numlist [COUNT];
    int sortedSel [COUNT];
    int sortedBub [COUNT];
    int sortedIns [COUNT];

    srand (time (NULL));

    genValues (numlist);
    copyVal (numlist, sortedSel, sortedBub, sortedIns);
    selectSort (sortedSel);
    bubbleSort (sortedBub);
    insertSort (sortedIns);
    newArray (sortedSel, sortedBub, sortedIns);
    selectSort (sortedSel);
    bubbleSort (sortedBub);
    insertSort (sortedIns);

    return 0;
}//main


void genValues (int numlist []) {
    printf ("\nThe 50 generated numbers are:\n");

    for (int ctr = 0; ctr < COUNT; ctr++) {
        numlist [ctr] = rand () % 1000 + 1;
        if ((ctr + 1) % 10 == 0) {
            printf (" %4d\n",numlist [ctr]);
        }
        else {
            printf (" %4d ", numlist [ctr]);
        }
    }

    return ;
}//genValues


void copyVal (int numlist [], int sortedSel [], int sortedBub [], int sortedIns []) {
    for (int ctr = 0; ctr < COUNT; ctr++) {
        sortedSel [ctr] = numlist [ctr];
        sortedBub [ctr] = numlist [ctr];
        sortedIns [ctr] = numlist [ctr];
    }

    return ;
}//copyVal

void selectSort (int sortedSel []) {
    int smallest;
    int temp;
    int moves = 0;
    int comparisons = 0;

    for (int ctr = 0; ctr < COUNT - 1; ctr++) {
        smallest = ctr + 1;
        for (int walk = smallest + 1; walk <= COUNT - 1; walk++) {
            if (sortedSel [walk] < sortedSel [smallest]) {
                smallest = walk;
            }
        }
        comparisons++;
        if (sortedSel [smallest] < sortedSel [ctr]) {
             temp = sortedSel [smallest];
             sortedSel [smallest] = sortedSel [ctr];
             sortedSel [ctr] = temp;
             moves++;
        }
    }

    //print ordered results
    printf ("\nBy using Selection Sort with %d comparisons and %d moves:\n", comparisons, moves);
    for (int ctr = 0; ctr < COUNT; ctr++) {
        if ((ctr + 1) % 10 == 0) {
            printf (" %4d\n", sortedSel [ctr]);
        }
        else {
            printf (" %4d ", sortedSel [ctr]);
        }
    }

    return ;
}//selectSort


void bubbleSort (int sortedBub []) {
    int temp;
    int comparisons = 0;
    int moves = 0;

    for (int ctr = 0; ctr < (COUNT - 1); ctr++) {
        for (int walk = (COUNT - 1); walk > ctr; walk--) {
            comparisons++;
            if (sortedBub [walk] < sortedBub [walk - 1]) {
                temp = sortedBub [walk];
                sortedBub [walk] = sortedBub [walk - 1];
                sortedBub [walk - 1] = temp;
                moves++;
            }
        }
    }

    //print ordered results
    printf ("\n\nBy using Bubble Sort with %d comparisons and %d moves:\n", comparisons, moves);
    for (int ctr = 0; ctr < COUNT; ctr++) {
        if ((ctr + 1) % 10 == 0) {
            printf (" %4d\n", sortedBub [ctr]);
        }
        else {
            printf (" %4d ", sortedBub [ctr]);
        }
    }

    return ;
}//bubbleSort


void insertSort (int sortedIns []) {
    int temp;
    int comparisons = 0;
    int moves = 0;

    for (int ctr = 0; ctr < (COUNT - 1); ctr++) {
        for (int walk = ctr + 1; walk > 0; walk--) {
            comparisons++;
            if (sortedIns [walk] < sortedIns [walk - 1]) {
                temp = sortedIns [walk];
                sortedIns [walk] = sortedIns [walk - 1];
                sortedIns [walk - 1] = temp;
                moves++;
            }
        }
    }

    //print ordered results
    printf ("\n\nBy using Insertion Sort with %d comparisons and %d moves:\n", comparisons, moves);
    for (int ctr = 0; ctr < COUNT; ctr++) {
        if ((ctr + 1) % 10 == 0) {
            printf (" %4d\n", sortedIns [ctr]);
        }
        else {
            printf (" %4d ", sortedIns [ctr]);
        }
    }

    return ;
}//insertSort


void newArray (int sortedSel [], int sortedBub [], int sortedIns []) {
    printf ("\n\nThe 2nd array to be sorted is a nearly ordered array derived\n");
    printf ("from the previously ordered array where every 10th number\nis subtracted by 5.\n");
    for (int ctr = 0; ctr < COUNT; ctr++) {
        if ((ctr + 1) % 10 == 0) {
            sortedSel [ctr] -= 5;
            sortedBub [ctr] = sortedSel [ctr];
            sortedIns [ctr] = sortedSel [ctr];
            printf (" %4d\n", sortedSel [ctr]);
        }
        else {
            printf (" %4d ", sortedSel [ctr]);
        }
    }

    return ;
}//selectSort2


