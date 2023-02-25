/* A program that creates an array of 100 random integers
in the range 1 to 200 and then, using the sequential search,
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
void seqSearch (int random [], int targetList [], int* numSearch, int* sucSearch, float* perSearch, int* aveTest);
void printData (int random [], int targetList [], int numSearch, int sucSearch, float perSearch, int aveTest);

int main (void)
{
    int random [COUNT];
    int targetList [COUNT];
    int numSearch = 0;
    int sucSearch = 0;
    float perSearch = 0;
    int aveTest = 0;

    genValues (random);
    seqSearch (random, targetList, &numSearch, &sucSearch, &perSearch, &aveTest);
    printData (random, targetList, numSearch, sucSearch, perSearch, aveTest);

    return 0;
}//main


void genValues (int random [])
{
    int x;
    srand (time (NULL));

    for (int i = 0; i < COUNT; i++)
    {
        x = rand () % 200 + 1;
        random [i] = x;
    }

    return ;
}//genValues


void seqSearch (int random [], int targetList [], int* numSearch, int* sucSearch, float* perSearch, int* aveTest)
{
    int target;

    for (int j = 0, i = 0; i < COUNT; i++)
    {
        target = rand () % 200 + 1;
        targetList [i] = target;

        for (j = 0; j < COUNT && random [j] != target; j++);

        if (random [j] == target)
            *sucSearch = *sucSearch + 1;

        *aveTest = *aveTest + j + 1;

        *numSearch = *numSearch + 1;
    }

    *perSearch = (*sucSearch * 1.0) / *numSearch;
    *aveTest = *aveTest / *numSearch;

    return ;
}//seqSearch


void printData (int random [], int targetList [], int numSearch, int sucSearch, float perSearch, int aveTest)
{
    printf ("\nThis program generates a random list of 100 integers from 1 to 200 and conducts 100 sequential searches");
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
}//printData
