/* A program that reads a floating-point number and prints
the ceiling, floor, and rounded value. */

#include <stdio.h>

double rounder (double inpnum);

int main (void)
{
    double x = 0;
    double y = 0;

    printf("Please enter a floating-point number: ");
    scanf ("%lf", &x);

    y = ceil (x);
    printf("\nCeiling: %4lf", y);

    y = floor (x);
    printf ("\nFloor: %4lf", y);

    y = rounder (x);
    printf ("\nRounded value: %4lf\n\n:", y);

    return 0;
}



//******************rounder****************************
 double rounder (double inpnum)
 {
     double z = 0;

     z = inpnum * 100;
     z = round (z);
     z = z / 100;

     return z;
 }
