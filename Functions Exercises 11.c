/* A program that has functions that compute the area and perimeter
of a right triangle when given the length of two sides (a and b). */

#include <stdio.h>
#include <math.h>

double triarea (double s1, double s2);
double triperi (double s1, double s2);

int main (void)
{
    double a = 0;
    double b = 0;
    double area, peri;

    printf ("First side: ");
    scanf ("%lf", &a);

    printf ("Second side: ");
    scanf ("%lf", &b);

    area = triarea (a,b);
    peri = triperi (a,b);

    printf ("\nArea: %.2lf square units", area);
    printf ("\nPerimeter: %.2lf units\n\n", peri);

    return 0;
}


//******************triarea************************
double triarea (double s1, double s2)
{
    return (0.5 * s1 * s2);
}

//******************triperi************************
double triperi (double s1, double s2)
{
    float hypo;

    hypo = sqrt (pow(s1,2) + pow(s2,2));

    return (hypo + s1 + s2);
}
