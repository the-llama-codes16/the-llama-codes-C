/* Write a function called "smallest" that, given three integers,
returns the smallest value. */

#include <stdio.h>

int smallest (int* a, int* b, int* c);

int main (void)
{
    int a, b, c;
    int ans;

    printf ("Enter 3 integers: ");
    scanf ("%d %d %d", &a, &b, &c);

    ans = smallest (&a, &b, &c);
    printf ("\nThe smallest among the three is %d\n", ans);

    return 0;
}//main

int smallest (int* a, int* b, int* c)
{
    int ans;

    if (*a < *b && *a < *c)
        ans = *a;
    else if (*b < *a && *b < *c)
        ans = *b;
    else if (*c < *a && *c < *b)
        ans = *c;

    return ans;
}//smallest
