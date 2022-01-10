/* A program that tests the value of num1.
If num1 is 10, square num1.
If num1 is 9, read a new value into num1.
If it is 2 or 3, multiply num1 by 99 and print out
the result.
Implement the code in nested if statements. */

#include <stdio.h>

int main (void)
{
    double num1;

    printf ("Enter a number: ");
    scanf ("%lf", &num1);

    if (num1 == 10)
        {
            num1 = pow (num1,2);
            printf ("\n%.2lf\n", num1);
        }//if num1 is 10

    else if (num1 == 9)
        {
            printf ("\nEnter a new number: ");
            scanf ("%lf", &num1);

            if (num1 == 2 || num1 == 3)
                {
                    num1 = num1 * 99;
                    printf ("\n%.2lf\n", num1);
                }//if num is 2 or 3

            if (num1 == 10)
                {
                    num1 = pow (num1,2);
                    printf ("\n%.2lf\n", num1);
                }//if num1 is 10
        }//if num is 9

    return 0;
}
