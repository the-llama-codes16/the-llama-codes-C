/* A program that reads a series of numbers and
calculates the average, geometric mean, and harmonic
mean

*/

#include <stdio.h>
#include <math.h>

void arithmetic (int sum, int counter);
void geometric (int product, int counter);
void harmonic (float inverse, int counter);

int main (void)
{
    int num;
    int sum = 0;
    int counter = 0;
    int product = 1;
    float inverse = 0;

    printf ("\n\tThis program calculates the average, geometric mean, and harmonic mean of the numbers you enter.");
    printf ("\n\tPlease enter a number (<Ctrl+D> to exit) : ");

    while (scanf ("%d", &num) == 1)
    {
        sum += num;
        product *= num;
        inverse += (1.0 / num);
        counter++;

        printf ("\tPlease enter another number: ");
    }

    arithmetic (sum, counter);
    geometric (product, counter);
    harmonic (inverse, counter);

    return 0;
}//main


void arithmetic (int sum, int counter)
{
    float ave;

    ave = (sum * 1.0) / counter;
    printf ("\n\tThe average is %.3f.", ave);

    return ;
}//arithmetic


void geometric (int product, int counter)
{
    float geo;

    geo = 1.0 * product;
    geo = pow (geo, (1.0 / counter));
    printf ("\n\tThe geometric mean is %.3f.", geo);

    return ;
}//geometric


void harmonic (float inverse, int counter)
{
     float harm;

     harm = (counter * 1.0) / inverse;
     printf ("\n\tThe harmonic mean is %.3f.\n", harm);

     return ;
}//harmonic
