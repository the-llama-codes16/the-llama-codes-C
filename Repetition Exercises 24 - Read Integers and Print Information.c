/* A program that reads a list of integers from the keyboard
and creates the following information:

a. Finds and prints the sum and the average of the integers
b. Finds and prints the largest and the smallest integer
c. Prints a Boolean (true or false) if any of them are less than 20
d. Prints a Boolean (true or false) if all of them are between 10 and 90

The input data consists of a list of integers with a sentinel.
The program prompts the user to enter the integers, one by one, and
enter the sentinel when the end of the list has been reached.

Enter numbers with <return> (99999 to stop):
*/


#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int main (void)
{
    int number;
    int largest = INT_MIN;
    int smallest = INT_MAX;
    int sum = 0;
    float ave;
    int counter = 0;

    bool less20;
    int switchA = 0;
    bool allbet1090;
    int switchB = 0;


    while (true)
    {
        printf ("\tPlease enter number (9999 to STOP): ");
        scanf ("%d", &number);

        if (number == 9999)
            break;

        sum += number;
        counter++;

        if (number > largest)
            largest = number;
        if (number < smallest)
            smallest = number;

        if (number < 20)
            less20 = true;
        if (number < 10 || number > 90)
            allbet1090 = false;
    }

    ave = sum / counter;

    printf ("\n\tThe number of integers is:         %3d", counter);
    printf ("\n\tThe sum of the integers is:       %4d", sum);
    printf ("\n\tThe average of the integers is:   %7.2f", ave);
    printf ("\n\tThe smallest integer is:           %3d", smallest);
    printf ("\n\tThe largest integer is:            %3d", largest);
    printf ("\n\tAt least one number was < 20:      ");
    if (less20 == 1)
        printf ("True");
    else
        printf ("False");

    printf ("\n\tAll numbers were (10 <= n >= 90):  ");
    if (allbet1090 == 1)
        printf ("True\n\n");
    else
        printf ("False\n\n");

    return 0;
}
