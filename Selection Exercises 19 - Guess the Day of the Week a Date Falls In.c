 /* A program that, given a certain date, would display
 the day of the week the date falls in.

 Note: Hints given, too long to type. */

 #include <stdio.h>

 void getData (int* month, int* day, int* year);
 int calcDay (int month, int day, int year);
 void printRes (int month, int day, int year, int dayCode);

 int main (void)
 {
     int month, day, year;
     int dayCode;

     getData (&month, &day, &year);
     //printf ("\n*** data from getData: %d %d %d\n", month, day, year);

     dayCode = calcDay (month, day, year);
     //printf ("\n*** data from calcDay: %d\n", dayCode);

     printRes (month, day, year, dayCode);

     return 0;
 }//main


void getData (int* month, int* day, int* year)
{
    printf ("\n\tThis program determines the day of the week a date falls in.");
    printf ("\n\tPlease enter date in digits, separated by spaces (mm dd yyyy): ");
    scanf ("%d %d %d", month, day, year);

    //check for input: month
    if (*month < 1 || *month > 12)
    {
        printf ("\tInvalid month. Please enter a number from 1 to 12.\n");
        exit (1);
    }

    //check for input: day
    if (*month == 9 || *month == 4 || *month == 6 || *month == 11)
    {
        if (*day < 1 || *day > 30)
        {
            printf ("\tInvalid day. Please enter a number from 1 to 30.\n");
            exit (1);
        }
    }

    else if (*month == 2)
    {
        if (!(*year % 100 == 0 && *year % 400 == 0))
        {
            if (*day > 28)
            {
                printf ("\tInvalid input. February %d only has 28 days.\n", *year);
                exit (1);
            }
        }
        else
        {
            if (*day > 29)
            {
                printf ("\tInvalid input. February %d only has 29 days.\n", *year);
                exit (1);
            }
        }
    }
    else
    {
        if (*day < 1 || *day > 31)
        {
            printf ("\tInvalid day. Please enter a number from 1 to 31.\n");
            exit (1);
        }
    }

    return ;
}//getData


 int calcDay (int month, int day, int year)
 {
     //calculate the day of the week for Dec 31 of the previous year
     int dayPrevYear, prevYear;

     prevYear = year - 1;
     dayPrevYear = (prevYear * 365 + (prevYear / 4) - (prevYear / 100) + (prevYear / 400)) % 7;
     //printf ("\n*** day of Dec 31 of the previous year: %d\n", dayPrevYear);

     //calculate the total number of days before the desired month
     int partialDays = 0;
     int totalDays, dayCode;

     switch (month)
     {
         case 12:
            partialDays = partialDays + 30;
         case 11:
            partialDays = partialDays + 31;
         case 10:
            partialDays = partialDays + 30;
         case 9:
            partialDays = partialDays + 31;
         case 8:
            partialDays = partialDays + 31;
         case 7:
            partialDays = partialDays + 30;
         case 6:
            partialDays = partialDays + 31;
         case 5:
            partialDays = partialDays + 30;
         case 4:
            partialDays = partialDays + 31;
         case 3:
            partialDays = partialDays + 28;
         case 2:
            partialDays = partialDays + 31;
     }

     //calculate dayCode
     totalDays = partialDays + day + dayPrevYear;
     dayCode = totalDays % 7;

     if (year % 4 == 0 && year % 100 == 0 || year % 400 == 0)
     {
         if (month > 2)
            dayCode++;
     }

     return dayCode;
}//calcDay


 void printRes (int month, int day, int year, int dayCode)
 {
     printf ("\n\tThe given date %2d / %2d / %4d falls on a: \n", month, day, year);

     switch (dayCode)
     {
        case 0:
            printf ("\t\tSunday\n");
            break;
        case 1:
            printf ("\t\tMonday\n");
            break;
        case 2:
            printf ("\t\tTuesday\n");
            break;
        case 3:
            printf ("\t\tWednesday\n");
            break;
        case 4:
            printf ("\t\tThursday\n");
            break;
        case 5:
            printf ("\t\tFriday\n");
            break;
        case 6:
            printf ("\t\tSaturday\n");
     }

     return ;
 }

