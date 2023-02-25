/* A program that randomly generates 100 numbers in the range 1 - 999
and stores a number as negative if it is divisible by 3 or 7. The
program will also have the following functions:

a. Print the array ten values to a line. The values will be aligned in rows.
b. Print the odd values, ten to a line.
c. Print the values at the odd numbered index locations, ten to a line.
d. Return a count of the number of even values.
e. Return the sum of all values in the array.
f. Return the location of the smallest value in the array.
g. Return the location of the largest value in the array.
h. Copy all positive values to a new array. Then use process "a"
to print the new array.
i. Copy all negative values to a new array. Then use process "a"
to print the new array.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define COUNT 100

void genValues (int numbers [], int* posCount, int* negCount);
void printArray (int count, int numbers [count]);
void printOdd (int numbers []);
void printOddIndex (int numbers []);
void countEven (int numbers []);
void sumVal (int numbers []);
void locSmallVal (int numbers []);
void locBigVal (int numbers []);
void storePos (int numbers [], int posCount, int posArray [posCount]);
void storeNeg (int numbers [], int negCount, int negArray [negCount]);

int main (void) {
    int numbers [COUNT];
    int posCount = 0;
    int negCount = 0;

    genValues (numbers, &posCount, &negCount);
    printArray (COUNT, numbers);
    printOdd (numbers);
    printOddIndex (numbers);
    countEven (numbers);
    sumVal (numbers);
    locSmallVal (numbers);
    locBigVal (numbers);

    int posArray [posCount];
    storePos (numbers, posCount, posArray);
    printArray (posCount, posArray);

    int negArray [negCount];
    storeNeg (numbers, negCount, negArray);
    printArray (negCount, negArray);

    return 0;
}//main


void genValues (int numbers [], int* posCount, int* negCount) {
    int value;

    srand (time (NULL));

    printf ("\nThis program generates 100 random integers in the range 1 - 999.\n");
    printf ("Any number divisible by 3 or 7 is stored as negative.\n");

    for (int ctr = 0; ctr < COUNT; ctr++) {
        value = rand () % 999 + 1;
        if (value % 3 == 0 || value % 7 == 0) {
            value = -value;
            *negCount = *negCount + 1; }
        else {
            *posCount = *posCount + 1; }
        numbers [ctr] = value;
    }

    return ;
}//genValues


void printArray (int count, int numbers [count]) {
    printf ("\na. Print the array ten values to a line. The values will be aligned in rows.\n");
    for (int ctr = 0; ctr < count; ctr++) {
        if (ctr != 0 && (ctr + 1) % 10 == 0) {
            printf ("%4d\n", numbers [ctr]); }
        else {
            printf ("%4d ", numbers [ctr]); }
    }

    return ;
}//printArray


void printOdd (int numbers []) {
    int counter = 1;

    printf ("\n\nb. Print the odd values, ten to a line.\n");
    for (int ctr = 0; ctr < COUNT; ctr++) {
        if (numbers [ctr] % 2 != 0) {
            printf ("%4d ", numbers [ctr]);

            if (counter % 10 == 0) {
                printf ("\n"); }
            counter++;
        }
    }

    return ;
}//printOdd


void printOddIndex (int numbers []) {
    int counter = 1;

    printf ("\n\nc. Print the values at the odd numbered index locations, ten to a line.\n");
    for (int ctr = 0; ctr < COUNT; ctr++) {
        if (ctr % 2 != 0) {
            printf ("%4d ", numbers [ctr]);

            if (counter % 10 == 0) {
                printf ("\n"); }
            counter++;
        }
    }

    return ;
}//printOddIndex


void countEven (int numbers []) {
    int even = 0;

    printf ("\n\nd. Return a count of the number of even values.\n");
    for (int ctr = 0; ctr < COUNT; ctr++) {
        if (numbers [ctr] % 2 == 0) {
            even++; }
    }

    printf ("%d", even);

    return ;
}//countEven


void sumVal (int numbers []) {
    int sum = 0;

    printf ("\n\ne. Return the sum of all values in the array.\n");
    for (int ctr = 0; ctr < COUNT; ctr++) {
        sum += numbers [ctr];
    }

    printf ("%d", sum);

    return ;
}//sumVal


void locSmallVal (int numbers []) {
    int loc;
    int smallest = INT_MAX;

    printf ("\n\nf. Return the location of the smallest value in the array.\n");
    for (int ctr = 0; ctr < COUNT; ctr++) {
        if (numbers [ctr] < smallest) {
            smallest = numbers [ctr];
            loc = ctr;
        }
    }

    printf ("%d", loc);

    return ;
}//locSmallVal


void locBigVal (int numbers []) {
    int loc;
    int largest = INT_MIN;

    printf ("\n\ng. Return the location of the largest value in the array.\n");
    for (int ctr = 0; ctr < COUNT; ctr++) {
        if (numbers [ctr] > largest) {
            largest = numbers [ctr];
            loc = ctr;
        }
    }

    printf ("%d", loc);

    return ;
}//locBigVal


void storePos (int numbers [], int posCount, int posArray [posCount]) {
    int posIndex = 0;

    printf ("\n\nh. Copy all positive values to a new array. Then use process 'a' to print the new array.");
    for (int ctr = 0; ctr < COUNT; ctr++) {
        if (numbers [ctr] > 0) {
            posArray [posIndex] = numbers [ctr];
            posIndex++;
        }
    }

    return ;
}//storePos


void storeNeg (int numbers [], int negCount, int negArray [negCount]) {
    int negIndex = 0;

    printf ("\n\ni. Copy all negative values to a new array. Then, use process 'a' to print the new array.");
    for (int ctr = 0; ctr < COUNT; ctr++) {
        if (numbers [ctr] < 0) {
            negArray [negIndex] = numbers [ctr];
            negIndex++;
        }
    }

    return ;
}//storeNeg

