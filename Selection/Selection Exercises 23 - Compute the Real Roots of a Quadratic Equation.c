/* A program that computes the real roots of a
quadratic equation (ax^2 + bx + c = 0).

The program will prompt the user to enter the constants
(a, b, c). It is then to display the roots
based on the following rules:

a. If both a and b are zero, there is no solution.
b. If a is zero, there is only one root (-c/b)
c. If the discriminate (b^2 - (4*a*c)) is negative, there
are no real roots.
d. For all other combinations, there are 2 roots. */

#include <stdio.h>

void getData (float* a, float* b, float* c);
void calcRoots (float a, float b, float c, float* rootA, float* rootB);


int main (void)
{
    float a, b, c;
    float rootA, rootB;

    getData (&a, &b, &c);
    printf ("\n*** data from getData: %.2f %.2f %.2f\n", a, b, c);

    calcRoots (a, b, c, &rootA, &rootB);

    return 0;
}//main


void getData (float* a, float* b, float* c)
{
    printf ("\n\tThis program displays the real roots of a quadratic equation.");
    printf ("\n\tPlease enter the required values:");
    printf ("\n\tax^2 + bx + c = 0");
    printf ("\n\ta: ");
    scanf ("%f", a);
    printf ("\tb: ");
    scanf ("%f", b);
    printf ("\tc: ");
    scanf ("%f", c);

    return ;
}//getData


void calcRoots (float a, float b, float c, float* rootA, float* rootB)
{
    float discriminate;

    discriminate = (pow (b, 2)) - (4 * a * c);

    if (a == 0 && b == 0)
    {
        printf ("\n\tBoth a and b are zero. There is no solution.\n");
        exit (1);
    }

    if (a == 0)
    {
        *rootA = -c / b;
        printf ("\n\ta is zero. There is only one root.");
        printf ("\n\t\troot: %.2f\n", *rootA);
        exit (1);
    }

    if (discriminate < 0)
    {
        printf ("\n\tThe discriminate is negative. There are no real roots.\n");
        exit (1);
    }

    *rootA = sqrt ((pow (b, 2)) - (4 * a * c));
    *rootA = - b + *rootA;
    *rootA = *rootA / (2 * a);

    *rootB = sqrt ((pow (b, 2)) - (4 * a * c));
    *rootB = - b - *rootB;
    *rootB = *rootB / (2 * a);

    printf ("\n\tThe roots are: %.2f and %.2f\n", *rootA, *rootB);

    return ;
}

