/* A program that asks the user to enter the current date
and a person's birth date in the form of month, day, year.
The program then calculates the person's age in integral
years. Use separate functions to enter the dates, calculate
the person's age, and print the results. */

#include <stdio.h>

void getCurrentDate (int* month, int* day, int* year);
void getBirthDate (int* bmonth, int* bday, int* byear);
int calcAge (int* month, int* day, int* year, int* bmonth, int* bday, int* byear);
void printRes (int age);

int main (void)
{
    int month, day, year;
    int bmonth, bday, byear;
    int age;

    getCurrentDate (&month, &day, &year);
    //printf ("\n***data from getCurrentDate: %d / %d / %d\n", month, day, year);

    getBirthDate (&bmonth, &bday, &byear);
    //printf ("\n***data from getBirthDate: %d / %d / %d\n", bmonth, bday, byear);

    age = calcAge (&month, &day, &year, &bmonth, &bday, &byear);
    //printf ("\n***data from calcAge: %d\n", age);

    printRes (age);

    return 0;
}//main


void getCurrentDate (int* month, int* day, int* year)
{
    //for current month
    printf ("\n\tThis program determines the age of a person in years.");
    printf ("\n\tPlease enter current date in digits.\n\t\tMonth: ");
    scanf ("%d", month);
    if (*month < 1 || *month > 12)
    {
        printf ("\tInvalid input. Please enter a number from 1 to 12.\n");
        exit (1);
    }

    //for current day
    printf ("\t\t  Day: ");
    scanf ("%d", day);
    if (*month == 9 || *month == 4 || *month == 6 || *month == 11)
    {
        if (*day < 1 || *day > 30)
        {
            printf ("\tInvalid input. Please enter a number from 1 to 30.\n");
            exit (1);
        }
    }
    else
    {
        if (*day < 1 || *day > 31)
        {
            printf ("\tInvalid input. Please enter a number from 1 to 31.\n");
            exit (1);
        }
    }

    //for current year
    printf ("\t\t Year: ");
    scanf ("%d", year);
    if (!(*year % 100 == 0 && *year % 400 == 0))
    {
        if (*month == 2)
        {
            if (*day > 28)
            {
                printf ("\tInvalid input. February %d only has 28 days.\n", *year);
                exit (1);
            }
        }
    }
    else
    {
        if (*month == 2)
        {
            if (*day > 29)
            {
                printf ("\tInvalid input. February %d only has 29 days.\n", *year);
                exit (1);
            }
        }
    }

    return ;
}//getCurrentDate


void getBirthDate (int* bmonth, int* bday, int* byear)
{
    //for birth month
    printf ("\n\tPlease enter the person's birth date in digits.\n\t\tMonth: ");
    scanf ("%d", bmonth);
    if (*bmonth < 1 || *bmonth > 12)
    {
        printf ("\tInvalid input. Please enter a number from 1 to 12.\n");
        exit (1);
    }

    //for birth day
    printf ("\t\t  Day: ");
    scanf ("%d", bday);
    if (*bmonth == 9 || *bmonth == 4 || *bmonth == 6 || *bmonth == 11)
    {
        if (*bday < 1 || *bday > 30)
        {
            printf ("\tInvalid input. Please enter a number from 1 to 30.\n");
            exit (1);
        }
    }
    else
    {
        if (*bday < 1 || *bday > 31)
        {
            printf ("\tInvalid input. Please enter a number from 1 to 31.\n");
            exit (1);
        }
    }

    //for birth year
    printf ("\t\t Year: ");
    scanf ("%d", byear);
    if (!(*byear % 100 == 0 && *byear % 400 == 0))
    {
        if (*bmonth == 2)
        {
            if (*bday > 28)
            {
                printf ("\tInvalid input. February %d only has 28 days.\n", *byear);
                exit (1);
            }
        }
    }
    else
    {
        if (*bmonth == 2)
        {
            if (*bday > 29)
            {
                printf ("\tInvalid input. February %d only has 29 days.\n", *byear);
                exit (1);
            }
        }
    }

    return ;
}//getBirthDate


int calcAge (int* month, int* day, int* year, int* bmonth, int* bday, int* byear)
{
    int age;

    if (*bmonth > *month)
        age = *year - *byear - 1;
    else
        age = *year - *byear;

    return age;
}//calcAge


void printRes (int age)
{
    printf ("\n\tThe person is %d years old.\n", age);

    return ;
}//printRes
