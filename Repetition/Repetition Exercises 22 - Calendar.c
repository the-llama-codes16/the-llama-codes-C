/* A program that creates a calendar for one year
and proceeds to another year if the user wants to.

PSEUDOCODE
main function:
do while loop:
    call makeCalendar function:
        declare int year, int daycode, int leapcode
        read year from user
        call leapyear function:
            parameter - year
            return - 1 if leapyear, 0 if not
        call Jan1 function:
            parameter - year
            return - day code
            determine what day the 1st day of the year falls in
        call calendar function:
            parameters - year and day code
            return - void
            display calendar for entire year
    ask if user wants to continue
while answer is yes

*/


#include <stdio.h>

void makeCalendar (void);
int leapcode (int year);
int dec (int year);
void calendar (int year, int daycodeDec, int leapcode);
int tempCal (int month, int days, int daycodePrevMonth, int year);

int main (void)
{
    char resp;

    do
    {
        makeCalendar ();

        printf ("\n\n\tDo you still want to continue?\n\tY - yes\n\tN - no\n\t: ");
        scanf (" %c", &resp);
        resp = toupper (resp);
    } while (resp == 'Y');

    return 0;
}//main


void makeCalendar (void)
{
    int year;
    int daycodeDec;
    int leapcode;

    printf ("\n\tThis program displays the calendar of the year you enter.");
    printf ("\n\tPlease enter year: ");
    scanf ("%d", &year);

    //Determine if year is a leap year
    leapcode = leapYear (year);

    //Determine the day of the week December 31 of previous year falls in
    daycodeDec = dec (year);

    //Print the calendar
    calendar (year, daycodeDec, leapcode);

    return ;
}//makeCalendar


int leapYear (int year)
{
    if (!(year % 4 && year % 100) || !(year % 400))
        return 1;
    else
        return 0;
}//leapYear


int dec (int year)
{
    int Dec31;
    int nyear;

    nyear = year - 1;
    Dec31 = (nyear * 365 + (nyear / 4) - (nyear / 100) + (nyear / 400)) % 7;

    return Dec31;
}//dec


void calendar (int year, int daycodeDec, int leapcode)
{
    int days;
    int daycodePrevMonth = daycodeDec;

    for (int m = 1; m <= 12; m++)
    {
        //assigning number of days on each month
        if (m == 4 || m == 6 || m == 9 || m == 11)
            days = 30;
        else if (m == 2)
        {
            if (leapcode == 1)
                days = 29;
            else
                days = 28;
        }
        else
            days = 31;

        //print calendar using template tempCal
        daycodePrevMonth = tempCal (m, days, daycodePrevMonth, year);
    }
}//calendar


int tempCal (int month, int days, int daycodePrevMonth, int year)
{
    int daycode;

    daycode = daycodePrevMonth;

    switch (month)
    {
        case 1:
            printf ("\n\tJANUARY                %4d", year);
            break;
        case 2:
            printf ("\n\tFEBRUARY               %4d", year);
            break;
        case 3:
            printf ("\n\tMARCH                  %4d", year);
            break;
        case 4:
            printf ("\n\tAPRIL                  %4d", year);
            break;
        case 5:
            printf ("\n\tMAY                    %4d", year);
            break;
        case 6:
            printf ("\n\tJUNE                   %4d", year);
            break;
        case 7:
            printf ("\n\tJULY                   %4d", year);
            break;
        case 8:
            printf ("\n\tAUGUST                 %4d", year);
            break;
        case 9:
            printf ("\n\tSEPTEMBER              %4d", year);
            break;
        case 10:
            printf ("\n\tOCTOBER                %4d", year);
            break;
        case 11:
            printf ("\n\tNOVEMBER               %4d", year);
            break;
        case 12:
            printf ("\n\tDECEMBER               %4d", year);
            break;
    }

    printf ("\n\tSUN MON TUE WED THU FRI SAT\n\t");

    for (int d = 0; d <= daycodePrevMonth; d++)
        printf ("    ");

    for (int i = 1; i <= days; i++)
    {
        if (daycode < 6)
        {
            printf ("%3d ", i);
            daycode++;
        }

        else
        {
            printf ("\n\t%3d ", i);
            daycode = 0;
        }
    }

    printf ("\n\n");

    return daycode;
}//tempCal

