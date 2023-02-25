/* A program that helps a prospective borrower calculate
the monthly payment for a loan. The program also prints
the amortization (payoff) table to show the balance of
the loan after each monthly payment.

PSEUDOCODE
variables: float principal, float rate, int years, float monthly, int months
read info
call monthlyPayment function:
    pre - principal, rate, years
    post - monthly
call printInfo function:
    pre - principal, rate, years, monthly, months
    post - void
call printAmorTable function:
    pre - principal, rate, years, monthly, months
    post - void

*/



#include <stdio.h>

float monthlyPayment (float principal, float rate, int months, float* q);
void displayInfo (float principal, float rate, int years, int months, float monthly);
void displayTable (float principal, float rate, float q, float monthly, int months);


int main (void)
{
    float principal;
    float rate;
    int years;
    int months;
    float monthly;
    float q;

    printf ("\n\tThis program will display your Monthly Amortization Table.");
    printf ("\n\tPlease enter the following details:");
    printf ("\n\tAmount of the loan (Principal)? ");
    scanf ("%f", &principal);
    printf ("\tInterest rate per year (%%)? ");
    scanf ("%f", &rate);
    printf ("\tNumber of years? ");
    scanf ("%d", &years);

    //Calculate the monthly payment
    months = years * 12;
    monthly = monthlyPayment (principal, rate, months, &q);
    //printf ("\n\t*** monthly: %f\n", monthly);

    //Display info
    displayInfo (principal, rate, years, months, monthly);

    //Display Amortization Table
    displayTable (principal, rate, q, monthly, months);

    return 0;
}//main


float monthlyPayment (float principal, float rate, int months, float* q)
{
    float monthly;
    float i;

    i = (rate / 12) / 100;
    *q = 1 + i;
    monthly = principal * pow (*q, months) * i;
    monthly = monthly / ((pow (*q, months)) - 1);

    return monthly;
}//monthlyPayment


void displayInfo (float principal, float rate, int years, int months, float monthly)
{
    printf ("\n");
    printf ("\n\tThe Amount of the loan (principal):  %7.2f", principal);
    printf ("\n\tInterest rate per year (percent):    %7.2f", rate);
    printf ("\n\tInterest rate per month (decimal):      %7f", rate/months/100);
    printf ("\n\tNumber of years:                     %4d", years);
    printf ("\n\tNumber of months:                    %4d", months);
    printf ("\n\tMonthly Payment:                     %7.2f\n\n", monthly);

    return ;
}//displayInfo


void displayTable (float principal, float rate, float q, float monthly, int months)
{
    float oldBal, intPaid, prinPaid, newBal;

    printf ("\tMonth     Old     Monthly    Interest    Principal    New\n");
    printf ("\t        Balance   Payment      Paid        Paid     Balance\n\n");

    //printf ("\t*%4d    %7.2f**   %7.2f**     %6.2f*      %6.2f*    %7.2f\n", i, oldBal, monthly, intPaid, prinPaid, newBal);


    oldBal = principal;
    rate = rate / months / 100;

    for (int i = 0; i < months; i++)
    {
        prinPaid = oldBal * rate / ( pow (q, (months - i)) - 1);
        intPaid = monthly - prinPaid;
        newBal = oldBal - prinPaid;

        printf ("\t%4d    %7.2f   %7.2f     %6.2f      %6.2f    %7.2f\n", i + 1, oldBal, monthly, intPaid, prinPaid, newBal);

        oldBal = newBal;
    }

    return ;
}

