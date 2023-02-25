/* A program that has a function that tests if
every element in array A[10] is equal to every element
in array B[10]. The function will return true if all
elements are equal and false if otherwise. */

#include <stdio.h>
#include <stdbool.h>

#define ARLENGTH 10

void getData (int A [], int B []);
bool compare (int A [], int B []);

int main (void)
{
    int A [ARLENGTH];
    int B [ARLENGTH];
    bool result;

    printf ("\n\tThis program compares two arrays and returns 1 if all elements are equal, 0 if otherwise.\n");
    getData (A, B);
    result = compare (A, B);

    printf ("\n\tResult: %d\n", result);

    return 0;
}//main


void getData (int A [], int B [])
{
    //receive elements for A
    printf ("\n\tFor array A:\n");
    for (int i = 0; i < ARLENGTH; i++)
    {
        printf ("\tEnter element %d out of %d: ", i + 1, ARLENGTH);
        scanf ("%d", &A[i]);
    }

    //receive elements for B
    printf ("\n\tFor array B:\n");
    for (int i = 0; i < ARLENGTH; i++)
    {
        printf ("\tEnter element %d out of %d: ", i + 1, ARLENGTH);
        scanf ("%d", &B[i]);
    }

    return ;
}//getData


bool compare (int A [], int B [])
{
    bool result = true;
    int i = 0;

    while (result == true && i < ARLENGTH)
    {
        if (A[i] != B[i])
            result = false;
        i++;
    }

    return result;
}//compare

