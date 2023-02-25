/* A program that prints either "zero" or "not zero"
depending on the integer variable num. */

#include <stdio.h>

int main (void)
{
    int num;

    printf ("Enter a number: ");
    scanf ("%d", &num);

    if (num == 0)
        printf ("zero\n");
    else
        printf ("not zero\n");

    return 0;
}
