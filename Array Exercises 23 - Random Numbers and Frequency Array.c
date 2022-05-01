/* A program that builds a frequency array for a
randomly-generated set of 100 numbers in the range
1 to 22. The array counts the number of values in
the range 1 to 19 and puts the others in an "invalid"
section. The histogram is then displayed in a vertical fashion:

--1- --2- --3- --4- --5- --6- --7- --8- --9- --10- ... Invalid

The program must also print the generated numbers
in 5 rows with 20 elements each row.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ITEMS 100

void genValues (int numlist []);
void freqArray (int numlist [], int freqList []);
void histogram (int numlist [], int freqList []);

int main (void) {
    int numlist [ITEMS];
    int freqList [21] = {0};

    srand (time (NULL));

    genValues (numlist);
    freqArray (numlist, freqList);
    histogram (numlist, freqList);

    return 0;
}//main


void genValues (int numlist []) {
    for (int ctr = 0; ctr < ITEMS; ctr++) {
        numlist [ctr] = rand () % 22 + 1;
    }

    return ;
}//genValues


void freqArray (int numlist [], int freqList []) {
    for (int ctr = 0; ctr < ITEMS; ctr++) {
        if (numlist [ctr] <= 19) {
            freqList [numlist [ctr]] += 1;
        }
        else {
            freqList [20] += 1;
        }
    }

    return ;
}//freqArray


void histogram (int numlist [], int freqList []) {
    for (int ctr = 0; ctr < ITEMS; ctr++) {
        if ((ctr + 1) % 10 == 0) {
            printf (" %4d\n", numlist [ctr]);
        }
        else {
            printf (" %4d", numlist [ctr]);
        }
    }

    printf ("\n\n");
    printf ("--1- --2- --3- --4- --5- --6- --7- --8- --9- --10 --11 --12 --13 --14 --15 --16 --17 --18 --19 Invalid\n");

    int num = 100;
    while (num != 0) {
        for (int ctr = 1; ctr < 21; ctr++) {
            if (freqList [ctr] > 0) {
                printf ("  x  ");
                freqList [ctr] -= 1;
                num--;
            }
            else {
                printf ("     ");
            }
        }
        printf ("\n");
    }

    return ;
}//histogram
