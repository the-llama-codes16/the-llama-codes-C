/* A program that reads integers from the keyboard.
If any of the numbers is negative, it returns a
negative number. If all the numbers are positive, it
returns their average.

PSEUDOCODE
initialize sum to zero
declare num, counter
declare ave
Call anyNegative function

anyNegative
    pre num
    post ave or neg number

    loop
    Enter number <Ctrl + D> to exit:
    while (scanf ("%d", &num) == 1)
        if num is 0 or greater than 0
            counter++
            sum
        else
            return -1

        return ave

    if num is pos
        sum = sum + num




*/

#include <stdio.h>

float anyNegative (void);

int main (void)
{
    float returnValue;

    returnValue = anyNegative ();

    printf ("\t%.2f\n", returnValue);

    return 0;
}//main


float anyNegative (void)
{
    int num;
    int counter = 0;
    int sum = 0;
    float ave = 0;
    printf ("\n\tThis program will return -1 if any of the numbers");
    printf ("\n\tis negative. If all are positive, the program will");
    printf ("\n\treturn the average of all numbers entered.");

    printf ("\n\n\tEnter a number: (<Ctrl+D+Enter> to exit)\n\t");
    while (scanf ("%d", &num) == 1)
    {
        if (num > 0)
        {
            counter++;
            sum += num;

        }
        else
            ave = -1;

        printf ("\tEnter another number: ");
    }

    if (ave != -1)
        ave = sum / counter;

    return ave;
}//anyNegative
