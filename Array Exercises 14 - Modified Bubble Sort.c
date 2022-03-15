/* A program that modifies a conventional bubble sort by
stopping the sort as soon as the inner loop no longer performs
exchanges. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define COUNT 100

void genValues (int numbers []);
void bubbleSort (int numbers []);

int main (void) {
    int numbers [COUNT];

    genValues (numbers);
    bubbleSort (numbers);

    return 0;
}//main


void genValues (int numbers []) {
    int value;

    srand (time (NULL));

    printf ("\nRandomly generated numbers: \n");
    for (int ctr = 0; ctr < COUNT; ctr++) {
        value = rand () % 100 + 1;
        numbers [ctr] = value;
        printf ("%4d ", numbers [ctr]);
    }

    return ;
}//genValues


void bubbleSort (int numbers []) {
    int pass  = COUNT - 1;
    int walk;
    int temp;
    int ctr = 0;
    bool sorted = false;

    while (ctr < pass && sorted == false) {
        walk = pass;
        int sortMove = 0;

        while (walk >= ctr) {
            if (numbers [walk] < numbers [walk - 1]) {
                temp = numbers [walk];
                numbers [walk] = numbers [walk - 1];
                numbers [walk - 1] = temp;

                sortMove++;
            }//if
            walk--;
        }//while

        if (sortMove == 0) {
            sorted = true;
        }

        ctr++;
    }//whileOuter

    printf ("\n\nAfter sorting: \n");
    for (int ctr = 0; ctr < COUNT; ctr++) {
        printf ("%4d ", numbers [ctr]);
    }
    return ;
}//bubbleSort
