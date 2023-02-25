/* A program containing a modified selection sort that
counts the number of exchanges required to sort a randomly
generated array of 50 integers. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 50

void genValues (int numbers []);
int selecSort (int numbers []);
void prinRes (int numbers [], int exchanges);

int main (void) {
    int numbers [COUNT];
    int exchanges;

    genValues (numbers);
    exchanges = selecSort (numbers);
    prinRes (numbers, exchanges);

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


int selecSort (int numbers []) {
    int pass = COUNT - 1;
    int exchange = 0;
    int smallest;
    int walk;
    int temp;

    for (int ctr = 0; ctr < pass; ctr++) {

        for (smallest = ctr + 1, walk = smallest ; walk < pass; walk++) {
            if (numbers [walk + 1] < numbers [smallest]) {
                smallest  = walk + 1;
            }
        }

        if (numbers [smallest] < numbers [ctr]) {
            temp = numbers [smallest];
            numbers [smallest] = numbers [ctr];
            numbers [ctr] = temp;
            exchange++;
        }
    }

    return exchange;
}//selectSort


void prinRes (int numbers [], int exchanges) {
    printf ("\nSorted result: \n");
    for (int ctr = 0; ctr < COUNT; ctr++) {
        printf ("%4d ", numbers [ctr]);
    }

    printf ("\n\nNumber of exchanges required to fully sort array: %d\n", exchanges);

    return ;
}//prinRes
