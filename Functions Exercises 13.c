/* This program receives the initial balance in a savings account
then prints the interest and balance for every quarter in 1 year.
Interest rate is 5.3% compounded quarterly. Separate functions for
computing interest and printing result must be used.

formula for Future worth in compound interest:

F = P * ((1 + (in / m)) ^ n)    */

#include <stdio.h>
#define IRATE 0.053
#define M 4

void HeaderPrint (double inAmount);
double inCalc (double* curAmount, float year);
void ResPrint (int quar, double inter, double curAmount);

int main (void)
{
    double Amount = 0;
    double Interest = 0;

    printf ("Please enter initial balance: ");
    scanf ("%lf", &Amount);

    HeaderPrint (Amount);

    Interest = inCalc (&Amount, 0.25);
    ResPrint (1, Interest, Amount);

    Interest = inCalc (&Amount, 0.25);
    ResPrint (2, Interest, Amount);

    Interest = inCalc (&Amount, 0.25);
    ResPrint (3, Interest, Amount);

    Interest = inCalc (&Amount, 0.25);
    ResPrint (4, Interest, Amount);

    return 0;
}

//***************HeaderPrint*******************
void HeaderPrint (double inAmount)
{
    printf ("\n\n");
    printf ("\tInitial Balance: %lf", inAmount);
    printf ("\n\n");
    printf ("\tQUARTER\t\tQUARTER INTEREST\tCUMULATIVE WORTH\n");

    return;
}

//***************inCalc************************
double inCalc (double* curAmount, float year)
{
    double i = 0, cur = 0;

    cur = *curAmount;
    i = pow ((1 + (IRATE/M)) , (year*M));
    i = i * (*curAmount);
    *curAmount = i;
    i = i - cur;

    return i;
}

//***************ResPrint**********************
void ResPrint (int quar, double inter, double curAmount)
{
    printf ("\t%d\t\t%lf\t\t%lf\n", quar, inter, curAmount);

    return;
}
