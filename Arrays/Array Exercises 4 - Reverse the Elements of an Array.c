/* A program that has a function that reverses the elements
of an array so that the last element becomes the first, the
second to the last element becomes the second, and so on.
The function is to reverse the elements in place without
using another array. It is permissible to use a variable to
hold the element temporarily. */

#include <stdio.h>

#define ARLENGTH 10

void getData (int sample []);
void reverseArray (int sample []);
void printRes (int sample []);

int main (void)
{
    int sample [ARLENGTH];

    printf ("\n\tThis program reverses the elements of an array.\n");
    getData (sample);
    reverseArray (sample);
    printRes (sample);

    return 0;
}//main


void getData (int sample [])
{
    //receive elements from user
    for (int i = 0; i < ARLENGTH; i++)
    {
        printf ("\tEnter element %d out of %d: ", i + 1, ARLENGTH);
        scanf ("%d", &sample[i]);
    }

    return ;
}


void reverseArray (int sample [])
{
    int temp;
    int lastInd = ARLENGTH - 1;
    int i = 0;
    int m;

    do
    {
        m = lastInd - i;
        temp = sample [i];
        sample [i] = sample [m];
        sample [m] = temp;
        i++;
    }while (i < m);

    return ;
}//reverseArray


void printRes (int sample [])
{
    printf ("\n\tThe reversed array is: \n\t");

    for (int i = 0; i < ARLENGTH; i++)
        printf ("%4d ", sample[i]);

    printf ("\n");

    return ;
}//printRes
