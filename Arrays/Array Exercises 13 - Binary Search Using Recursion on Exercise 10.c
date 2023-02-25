/* A program that uses recursion to implement a binary search.
The principle is used to modify Array Exercises 10: Array of 100
Integers with Binary Search. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 20

void genValues (int random []);
void arraySort (int random []);
void binSearch (int random [], int targetList [], int* numSearch, int* sucSearch, float* perSearch, int* aveTest);
void binRecur (int random [], int first, int last, int target, int* sucSearch, int* aveTest);
void printRes (int random [], int targetList [], int numSearch, int sucSearch, float perSearch, int aveTest);

int main (void){
    int random [COUNT];
    int targetList [COUNT];
    int numSearch = 0;
    int sucSearch = 0;
    float perSearch = 0;
    int aveTest = 0;

    genValues (random);
    arraySort (random);
    binSearch (random, targetList, &numSearch, &sucSearch, &perSearch, &aveTest);
    printRes (random, targetList, numSearch, sucSearch, perSearch, aveTest);

    return 0;
}//main


void genValues (int random []) {
    int value;

    srand (time (NULL));

    for (int cntr = 0; cntr < COUNT; cntr++){
        value = rand () % 200 + 1;
        random [cntr] = value;
    }

    return ;
}//genValues


void arraySort (int random []) {
    int smallest;
    int pass = COUNT - 1;
    int temp;

    for (int cntr = 0; cntr < pass; cntr++) {
        smallest = cntr;

        for (int walk = cntr + 1; walk < COUNT; walk++) {
            if (random [walk] < random [smallest]){
                smallest  = walk;
            }
        }

        temp = random [cntr];
        random [cntr] = random [smallest];
        random [smallest] = temp;
    }

    return ;
}//arraySort


void binSearch (int random [], int targetList [], int* numSearch, int* sucSearch, float* perSearch, int* aveTest) {
    int target;
    int first;
    int last;
    int found = 0;
    int test = 0;

    for (int cntr = 0; cntr < COUNT; cntr++) {
        target = rand () % 200 + 1;
        targetList [cntr] = target;

        first = 0;
        last = COUNT - 1;

        binRecur (random, first, last, target, &sucSearch, &aveTest);
        *numSearch = *numSearch + 1;
    }

    *perSearch = (*sucSearch * 1.0) / *numSearch;
    *aveTest = *aveTest / *numSearch;

    return ;
}//binSearch


void binRecur (int random [], int first, int last, int target, int* sucSearch, int* aveTest) {
    int mid;
    int found;
    int test;

    if (first > last) {
        *aveTest = test;
        *sucSearch = found;
        return ;
    }

    else {
        test = test + 1;
        mid = (first + last) / 2;

        if (random [mid] > target) {
            last = mid - 1;
        }

        else if (random [mid] < target) {
            first = mid + 1;
        }

        else if (random [mid] == target) {
            first = last + 1;
            found = found + 1;
        }

        binRecur (random, first, last, target, &sucSearch, &aveTest);
    }
}//binRecur


void printRes (int random [], int targetList [], int numSearch, int sucSearch, float perSearch, int aveTest) {
    printf ("\nThis program generates a random list of 100 integers from 1 to 200 and conducts 100 binary searches");
    printf ("\nusing 100 targets that have also been randomly generated.\n");

    printf ("\nThe list of randomly generated integers is:\n");
    for (int i = 0; i < COUNT; i++) {
        printf ("%4d ", random [i]);
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

    printf ("\n\nResults:");
    printf ("\n1. Number of searches conducted:         %4d", numSearch);
    printf ("\n2. Number of successful searches:        %4d", sucSearch);
    printf ("\n3. Percentage of successful searches:    %3.2f", perSearch);
    printf ("\n4. Average number of tests per search:   %4d\n", aveTest);

    return ;
}//printRes



  /* while (first < last) {
            *aveTest = *aveTest + 1;
            mid = (first + last) / 2;

            if (random [mid] > target) {
                last = mid - 1;
            }

            else if (random [mid] < target) {
                first = mid + 1;
            }

            else if (random [mid] == target) {
                *sucSearch = *sucSearch + 1;
                first = last + 1;
            }
        }*/


