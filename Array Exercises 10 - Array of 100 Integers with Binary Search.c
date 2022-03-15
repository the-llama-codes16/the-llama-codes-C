/* A program that creates an array of 100 random integers
in the range 1 to 200 and then, using binary search,
searches the array 100 times using randomly generated targets
in the same range. At the end of the program, the following
must be displayed.
a. The number of searches completed
b. The number of successful searches
c. The percentage of successful searches
d. The average number of tests per search
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 100

void genValues (int random []);
void arraySort (int random []);
void binSearch (int random [], int targetList [], int* numSearch, int* sucSearch, float* perSearch, int* aveTest);
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
    int mid;

    for (int cntr = 0; cntr < COUNT; cntr++) {
        target = rand () % 200 + 1;
        targetList [cntr] = target;

        first = 0;
        last = COUNT - 1;

        while (first < last) {
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
        }

        *numSearch = *numSearch + 1;
    }

    *perSearch = (*sucSearch * 1.0) / *numSearch;
    *aveTest = *aveTest / *numSearch;

    return ;
}//binSearch


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

