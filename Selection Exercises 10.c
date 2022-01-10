/* Write a function called day_of_the_week that, given an
integer between 0 and 6, prints the corresponding day
of the week. Assume that the first day of the week (0)
is Sunday. */

#include <stdio.h>

void day_of_the_week (int day);

int main (void)
{
    int day;

    printf ("Enter a number from 0 to 6: ");
    scanf ("%d", &day);

    if (!(day > 6 || day < 0))
        day_of_the_week (day);
    else
        printf ("\nInvalid input.\n");

    return 0;
}//main

void day_of_the_week (int day)
{
    switch (day)
    {
        case 0:
            printf ("\nSunday\n");
            break;
        case 1:
            printf ("\nMonday\n");
            break;
        case 2:
            printf ("\nTuesday\n");
            break;
        case 3:
            printf ("\nWednesday\n");
            break;
        case 4:
            printf ("\nThursday\n");
            break;
        case 5:
            printf ("\nFriday\n");
            break;
        case 6:
            printf ("\nSaturday\n");
    }//switch day

    return ;
}//day_of_the_week
