/* A program that allows the user to enter five numbers
and then choose between finding the smallest, largest,
sum, or average. The menu and all the choices are functions.
A switch statement will be used to determine what action
to take. An error message should show up if an invalid choice
is entered. */

#include <stdio.h>

void menu (int a, int b, int c, int d, int e);
int smallest (int a, int b, int c, int d, int e);
int largest (int a, int b, int c, int d, int e);
int sum (int a, int b, int c, int d, int e);
float average (int a, int b, int c, int d, int e);

int main (void)
{
    int a, b, c, d, e;

    printf ("\n\tPlease enter 5 numbers: ");
    scanf ("%d %d %d %d %d", &a, &b, &c, &d, &e);

    menu (a, b, c, d, e);

    return 0;
}//main


void menu (int a, int b, int c, int d, int e)
{
    int choice;
    int result;
    float ave;

    printf ("\n\tPlease press key according to what you want to determine.");
    printf ("\n\t1. Smallest\n\t2. Largest\n\t3. Sum\n\t4. Average");
    printf ("\n\tYour choice: ");
    scanf ("%d", &choice);

    switch (choice)
    {
        case 1:
            result = smallest (a, b, c, d, e);
            printf ("\n\tSmallest: %d\n", result);
            break;
        case 2:
            result = largest (a, b, c, d, e);
            printf ("\n\tLargest: %d\n", result);
            break;
        case 3:
            result = sum (a, b, c, d, e);
            printf ("\n\tSum: %d\n", result);
            break;
        case 4:
            ave = average (a, b, c, d, e);
            printf ("\n\tAverage: %.2f\n", ave);
            break;
        default:
            printf ("\n\tInvalid input. Please enter a number from 1 to 4.\n");
    }

    return ;
}//menu


int smallest (int a, int b, int c, int d, int e)
{
    int result;

    result = a;
    if (a > b)
        result = b;
    if (result > c)
        result = c;
    if (result > d)
        result = d;
    if (result > e)
        result = e;

    return result;
}//smallest


int largest (int a, int b, int c, int d, int e)
{
    int result;

    result = a;
    if (result < b)
        result = b;
    if (result < c)
        result = c;
    if (result < d)
        result = d;
    if (result < e)
        result = e;

    return result;
}//largest


int sum (int a, int b, int c, int d, int e)
{
    return (a + b + c + d + e);
}//sum


float average (int a, int b, int c, int d, int e)
{
    float ave;

    ave = (a + b + c + d + e) / 5.0;

    return ave;
}//average
