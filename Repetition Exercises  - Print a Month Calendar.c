/* A program that prints a month calendar given the day
the month starts and the total number of days */

#include <stdio.h>

void printMonth (int startDay, int totalDays);

int main (void)
{
    int startDay, totalDays;

    printf ("\n\tEnter the starting day of the month:");
    printf ("\n\tEnter (0 for Sunday, 1 for Monday, 2 for Tuesday, etc)");
    scanf ("%d", &startDay);

    printf ("\tEnter total number of days: ");
    scanf ("%d", &totalDays);

    printMonth (startDay, totalDays);

    return 0;
}//main


void printMonth (int startDay, int totalDays)
{
    int weekDay;

    //print headers
    printf ("\n\tSun Mon Tue Wed Thu Fri Sat");
    printf ("\n\t--- --- --- --- --- --- ---\n\t");

    for (weekDay = 0; weekDay < startDay; weekDay++)
     {
         printf ("    ");
     }

    for (int day = 1; day <= totalDays; day++)
    {
        if (weekDay > 6)
        {
            weekDay = 1;
            printf ("\n\t");
        }
        else
        {
            weekDay++;
        }

        printf ("%3d ", day);
    }

    return ;
}//printMonth
