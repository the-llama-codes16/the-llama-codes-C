/* A function that converts a Julian date to a month and day.

Julian date = a year and the day of the year relative to Jan 1.
Example: February 10 is day 41.

The month and the day are to be stored in integer variables whose
addresses are passed as parameters. The function is also to handle
leap years.

If there is an error in a parameter, such as a day greater than 366,
the function will return 0. Otherwise, it returns a positive number.

*/

#include <stdio.h>
#include <stdbool.h>

void getData (int* jdate, int* year);
void convDate (int jdate, int year, int* month, int* day, bool* leap);
void printRes (int jdate, int year, int month, int day);

int main (void) {
    int jdate;
    int year;
    int month;
    int day;
    bool leap;

    getData (&jdate, &year);
    convDate (jdate, year, &month, &day, &leap);
    printRes (jdate, year, month, day);

    return 0;
}//main


void getData (int* jdate, int* year) {

    printf ("\nThis program converts a Julian date to its corresponding month and day.\n");
    printf ("Example: February 10 is day 41\n");
    printf ("\nPlease enter the year: ");
    scanf ("%d", year);
    printf ("\nPlease enter the day: ");
    scanf ("%d", jdate);

    return ;
}//getData


void convDate (int jdate, int year, int* month, int* day, bool* leap) {
    *leap = false;
    *month = 1;
    int sumdays = 0;

    //leap year checking
    if ((year % 4 == 0 && year % 100 == 0) || (year % 400 == 0)) {
        *leap = true;
    }
    if (*leap == false && jdate > 365) {
        *month = 0;
        *day = 0;
        return ;
    }


    switch (*month) {
        case (1):
            sumdays = 31;
            if (jdate <= sumdays) {
                break; }
            jdate -= sumdays;
        case (2):
            if (*leap == true) {
                sumdays = 29; }
            else {
                sumdays = 28; }
            (*month)++;
            if (jdate <= sumdays) {
                break; }
            jdate -= sumdays;
        case (3):
            sumdays = 31;
            (*month)++;
            if (jdate <= sumdays) {
                break; }
            jdate -= sumdays;
        case (4):
            sumdays = 30;
            (*month)++;
            if (jdate <= sumdays) {
                break; }
            jdate -= sumdays;
        case (5):
            sumdays = 31;
            (*month)++;
            if (jdate <= sumdays) {
                break; }
            jdate -= sumdays;
        case (6):
            sumdays = 30;
            (*month)++;
            if (jdate <= sumdays) {
                break; }
            jdate -= sumdays;
        case (7):
            sumdays = 31;
            (*month)++;
            if (jdate <= sumdays) {
                break; }
            jdate -= sumdays;
        case (8):
            sumdays = 31;
            (*month)++;
            if (jdate <= sumdays) {
                break; }
            jdate -= sumdays;
        case (9):
            sumdays = 30;
            (*month)++;
            if (jdate <= sumdays) {
                break; }
            jdate -= sumdays;
        case (10):
            sumdays = 31;
            (*month)++;
            if (jdate <= sumdays) {
                break; }
            jdate -= sumdays;
        case (11):
            sumdays = 30;
            (*month)++;
            if (jdate <= sumdays) {
                break; }
            jdate -= sumdays;
        case (12):
            sumdays = 31;
            (*month)++;
            if (jdate <= sumdays) {
                break; }
            jdate -= sumdays;
    }

    *day = jdate;

    return ;
}//convDate


void printRes (int jdate, int year, int month, int day) {
    if (month == 0) {
        printf ("\nYear provided is a leap year. Please check the day entered.\n");
    }

    printf ("day %d of year %d is %d/%d/%d\n", jdate, year, month, day, year);

    return ;
}//printRes

