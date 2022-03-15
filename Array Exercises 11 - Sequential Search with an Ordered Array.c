/* A program that uses sequential search on an ordered list
and terminates right away as soon as the current element is
greater than the target.

ADDED FOR PRACTICE: Use bubble sort to sort randomly generated
integers. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define COUNT 50

void genValues (int sample []);
void arraySort (int sample []);
bool seqSearch (int sample [], int* target, int* stop);
void printRes (int sample [], int target, int stop, bool found);

int main (void) {
    int sample [COUNT];
    int target;
    int stop;
    bool found;

    genValues (sample);
    arraySort (sample);
    found = seqSearch (sample, &target, &stop);
    printRes (sample, target, stop, found);

    return 0;
}//main


void genValues (int sample []) {
    int value;

    srand (time (NULL));

    for (int ctr = 0; ctr < COUNT; ctr++) {
        value = rand () % 200 + 1;
        sample [ctr] = value;
    }

    return ;
}//genValues


void arraySort (int sample []) {
    int temp;
    int last = COUNT - 1;
    int walk;

    for (int ctr = 0; ctr < last; ctr++) {
        walk = last;

        while (walk > ctr) {
            if (sample [walk] < sample [walk - 1]) {
                temp = sample [walk];
                sample [walk] = sample [walk - 1];
                sample [walk - 1] = temp;
            }

            walk--;
        }
    }

    return ;
}//arraySort


bool seqSearch (int sample [], int* target, int* stop) {
    int ctr = 0;

    printf ("\nEnter a number from 1 to 200: ");
    scanf ("%d", target);

    while (ctr < COUNT && sample [ctr] < *target) {
        ctr++;
    }

    *stop = sample [ctr];
    if (*stop == *target)
        return true;
    else
        return false;
}//seqSearch


void printRes (int sample [], int target, int stop, bool found) {
    printf ("\nThis program uses sequential search on an ordered array and stops");
    printf ("\nas soon as the current element is greater than the target.\n");

    printf ("\nThe ordered array is:\n");
    for (int ctr = 0; ctr < COUNT; ctr++) {
        printf ("%4d ", sample [ctr]);
    }

    printf ("\n\nThe target is: %d", target);

    printf ("\nFound: ");
    if (found == true) {
        printf ("Yes");
    }
    else {
        printf ("No");
    }
    printf ("\nThe search stopped at: %d\n", stop);

    return ;
}//printRes
