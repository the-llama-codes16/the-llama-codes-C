/* A program that computes payroll earnings statement
given earnings, bonus, and tax rates */

#include <stdio.h>
#define FEDERALTR 0.25
#define STATETR 0.10
#define RETIREMENT 0.08
#define COM 0.125

double grossearnfun (double sales, double bonus);
double totaltaxfun (double grosspay);

int main (void)
{
    double tSales, bonus;
    double grossEarning;
    double netEarning;


    printf ("Please enter total sales: ");
    scanf ("%lf", &tSales);

    printf ("Please enter bonus: ");
    scanf ("%lf", &bonus);

    grossEarning = grossearnfun (tSales, bonus);
    printf ("\n\nGross Pay: %lf", grossEarning);

    netEarning = grossEarning - totaltaxfun (grossEarning);
    printf ("\nNet Pay: %lf\n\n", netEarning);

    return 0;
}


//********************grossearnfun************************
double grossearnfun (double sales, double bonus)
{
    return ((sales * COM) + bonus);
}


//********************totaltaxfun*************************
double totaltaxfun (double grosspay)
{
     double taxtotal;

     taxtotal = FEDERALTR + STATETR + RETIREMENT;

     return (taxtotal * grosspay);
}

