/* A program that sets best to 1 if the score provided is
greater than or equal to 90. */

#include<stdio.h>

int main (void)
{
    int best = 0;
    int score;

    printf ("score: ");
    scanf ("%d", &score);

    if (score >= 90)
        best = 1;

    printf ("best: %d\n", best);

    return 0;
}

