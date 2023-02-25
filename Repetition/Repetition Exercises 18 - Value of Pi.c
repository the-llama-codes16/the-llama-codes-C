/* A program that displays the value of pi
given n = 5 and n = 10.

pi = sqrt (6 * ((1/1^2) + (1/2^2) + (1/3^2) + ... + (1/limit^)))

PSEUDOCODE
declare int n, float pie
call function pieCalc
print pi for n=5 and n=10

pieCalc function
    input n
    output pie

    declare pie
    initialize float x = 0
    for loop
        x += 1 / pow (i,2)
    pie = sqrt (6 * x)

    return pie
*/

#include <stdio.h>
#include <math.h>

float pieCalc (int n);

int main (void)
{
    float pie;

    //Value of pie when n = 5
    pie = pieCalc (5);
    printf ("\n\tThe value of pi when n = 5 is %f.\n", pie);

    //Value of pie when n = 10
    pie = pieCalc (10);
    printf ("\n\tThe value of pi when n = 10 is %f.\n", pie);

    return 0;
}//main


float pieCalc (int n)
{
    float pie;
    float x = 0;

    for (int i = 1; i <= n; i++)
        x+= (1 / pow (i,2));

    pie = sqrt (6 * x);

    return pie;
}//pieCalc
