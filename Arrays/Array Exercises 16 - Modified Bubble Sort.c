/* A program containing a modified bubble sort that
counts the number of exchanges required to sort a randomly
generated array of 50 integers. */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 50

void genValues (int numbers []);
int bubbleSort (int numbers []);
void prinRes (int numbers [], int exchanges);

int main (void) {
    int numbers [COUNT];
    int exchanges;

    genValues (numbers);
    exchanges = bubbleSort (numbers);
    prinRes (numbers, exchanges);

    return 0;
}//main


void genValues (int numbers []) {
    int value;

    srand (time (NULL));

    printf ("\nRandomly generated numbers: \n");
    for (int ctr = 0; ctr < COUNT; ctr++) {
        value = rand () % 200 + 1;
        numbers [ctr] = value;
        printf ("%4d ", value);
    }

    return ;
}//genValues


int bubbleSort (int numbers []) {
    int pass = COUNT - 1;
    int change = 0;
    int temp;

    for (int ctr = 0; ctr < pass; ctr++) {
        for (int walk = pass; walk > ctr; walk--) {
            if (numbers [walk] < numbers [walk - 1]) {
                temp = numbers [walk];
                numbers [walk] = numbers [walk - 1];
                numbers [walk - 1] = temp;
                change++;
            }
        }
    }

    return change;
}//bubbleSort


void prinRes (int numbers [], int exchanges) {
    printf ("\nThe sorted result is: \n");

    for (int ctr = 0; ctr < COUNT; ctr++) {
        printf ("%4d ", numbers [ctr]);
    }

    printf ("\n\nThe number of bubble sort exchanges required to sort the array is: %d\n", exchanges);

    return ;
}//prinRes
