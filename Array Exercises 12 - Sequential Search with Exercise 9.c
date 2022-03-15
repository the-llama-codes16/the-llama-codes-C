/* A program that creates an array of 100 random integers
in the range 1 to 200 that are then sorted. Then, using
the sequential search, searches the array 100 times using
randomly generated targets in the same range. Each search stops
as soon as the current element is greater than the target.

At the end of the program, the following
must be displayed:

a. The number of searches completed
b. The number of successful searches
c. The percentage of successful searches
d. The average number of tests per search

ADDED FOR PRACTICE: Sort using insertion method
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 100

void genValues (int sample []);
void arraySort (int sample []);
void seqSearch (int sample [], int targetList [], int stopIndex [], int* numSearch, int* sucSearch, float* perSearch, int* aveTest);
void printData (int sample [], int targetList [], int stopIndex [], int numSearch, int sucSearch, float perSearch, int aveTest);

int main (void) {
    int sample [COUNT];
    int targetList [COUNT];
    int stopIndex [COUNT];
    int numSearch = 0;
    int sucSearch = 0;
    float perSearch = 0;
    int aveTest = 0;

    genValues (sample);
    arraySort (sample);
    seqSearch (sample, targetList, stopIndex, &numSearch, &sucSearch, &perSearch, &aveTest);
    printData (sample, targetList, stopIndex, numSearch, sucSearch, perSearch, aveTest);

    return 0;
}//main


void genValues (int sample [])
{
    int value;
    srand (time (NULL));

    for (int ctr = 0; ctr < COUNT; ctr++)
    {
        value = rand () % 200 + 1;
        sample [ctr] = value;
    }

    return ;
}//genValues


void arraySort (int sample []) {
   int pass = COUNT - 1;
   int step;
   int temp;

   for (int current = 1; current <= pass; current++) {
       step = current - 1;

       while (step >= 0) {
            if (sample [step + 1] < sample [step]) {
                temp = sample [step + 1];
                sample [step + 1] = sample [step];
                sample [step] = temp;
            }
            step--;
       }
   }

   return ;
}//arraySort


void seqSearch (int sample [], int targetList [], int stopIndex [], int* numSearch, int* sucSearch, float* perSearch, int* aveTest) {
    int target;
    int step;

    for (int ctr = 0; ctr < COUNT; ctr++) {
        target = rand () % 200 + 1;
        targetList [ctr] = target;
    }

    for (int ctr = 0; ctr < COUNT; ctr++) {
        step = 0;

        while (step < COUNT && sample [step] < targetList [ctr]) {
            step++;
        }

        stopIndex [ctr] = step;

        if (sample [step] == targetList [ctr]) {
            *sucSearch = *sucSearch + 1;
        }

        *numSearch = *numSearch + 1;
        *aveTest = *aveTest + step + 1;

    }

    *perSearch = *sucSearch * 1.0 / *numSearch;
    *aveTest = *aveTest / *numSearch;

    return ;
}//seqSearch

void printData (int sample [], int targetList [], int stopIndex [], int numSearch, int sucSearch, float perSearch, int aveTest)
{
    printf ("\nThis program generates a random list of 100 integers from 1 to 200 that have been sorted, then conducts");
    printf ("\n100 sequential searches using 100 targets that have also been randomly generated.");
    printf ("\nThe search stops if the current element is greater than or equal to the target.\n");

    printf ("\nThe list of randomly generated and sorted integers is:\n");
    for (int i = 0; i < COUNT; i++) {
        printf ("%4d ", sample [i]);
        if (i != 0 && !((i+1) % 10)) {
            printf ("\n");
        }
    }

    printf ("\n\nAnd the list of randomly generated targets is:\n");
    for (int i = 0; i < COUNT; i++) {
        printf ("%4d ", targetList [i]);
        if (i != 0 && !((i+1) % 10)) {
            printf ("\n");
        }
    }

    printf ("\n\nThe indexes each search stopped on are: \n");
    for (int i = 0; i < COUNT; i++) {
        printf ("%4d ", stopIndex [i]);
        if (i != 0 && !((i+1) % 10)) {
            printf ("\n");
        }
    }

    printf ("\n\nResults:");
    printf ("\n1. Number of searches conducted:         %4d", numSearch);
    printf ("\n2. Number of successful searches:        %4d", sucSearch);
    printf ("\n3. Percentage of successful searches:    %3.2f", perSearch);
    printf ("\n4. Average number of tests per search:   %4d\n", aveTest);

    return ;
}//printData

