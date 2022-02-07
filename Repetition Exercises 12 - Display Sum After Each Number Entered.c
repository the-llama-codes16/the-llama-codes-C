/* A program that receives numbers from user
and displays the total as each number is entered. */

#include <stdio.h>

int main (void)
{
    int num;
    int sum = 0;

    printf ("\n\tEnter your numbers: <Ctrl+D+Enter to stop>\n\t");

    while (scanf ("%d", &num) != 0)
    {
        sum = sum + num;
        printf ("\tTotal: %d\n\t", sum);
    }

    return 0;
}
