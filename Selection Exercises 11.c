/* Write a function called month_of_year that,
given an integer between 1 and 12, prints out the
corresponding month of the year. */

#include <stdio.h>

void month_of_year (int month);

int main (void)
{
    int month;

    printf ("Please enter a number from 1 to 12: ");
    scanf ("%d", &month);

    if (!(month < 1 || month > 12))
        month_of_year (month);
    else
        printf ("\nInvalid input\n");

    return 0;
}//main

void month_of_year (int month)
{
    switch (month)
    {
        case 1:
            printf ("\nJanuary\n");
            break;
        case 2:
            printf ("\nFebruary\n");
            break;
        case 3:
            printf ("\nMarch\n");
            break;
        case 4:
            printf ("\nApril\n");
            break;
        case 5:
            printf ("\nMay\n");
            break;
        case 6:
            printf ("\nJune\n");
            break;
        case 7:
            printf ("\nJuly\n");
            break;
        case 8:
            printf ("\nAugust\n");
            break;
        case 9:
            printf ("\nSeptember\n");
            break;
        case 10:
            printf ("\nOctober\n");
            break;
        case 11:
            printf ("\nNovember\n");
            break;
        case 12:
            printf ("\nDecember\n");
    }//switch month

    return ;
}//month_of_year
