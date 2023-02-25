/* A program that performs division. Assume divisor and dividend
as integers and quotient as double. Assign 0 to quotient if divisor
is 0. */

#include <stdio.h>

int main (void)
{
    int dividend, divisor;
    double quotient;

    printf ("Dividend: ");
    scanf ("%d", &dividend);
    printf ("\nDivisor: ");
    scanf ("%d", &divisor);

    if (divisor == 0)
        quotient = 0;
    else
        quotient = dividend / divisor;

    printf ("\nDividend: %d", dividend);
    printf ("\nDivisor: %d", divisor);
    printf ("\nQuotient: %lf\n", quotient);

    return 0;
}
