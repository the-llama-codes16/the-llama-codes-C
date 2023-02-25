/* A program that has a function that receives a floating-point number
and rounds the result to two decimal places. */

#include<stdio.h>

 double rounder (double inpnum);

 int main (void)
 {
     double x,y;

     printf ("This program rounds a floating-point number to two decimal places.\n");
     printf ("Please enter a number: ");
     scanf ("%lf", &x);

     y = rounder (x);

     printf ("\n%lf rounds up to %lf\n\n", x,y);

     return 0;
 }


 //******************rounder****************************
 double rounder (double inpnum)
 {
     double z;

     z = inpnum * 100;
     z = round (z);
     z = z / 100;

     return z;
 }
