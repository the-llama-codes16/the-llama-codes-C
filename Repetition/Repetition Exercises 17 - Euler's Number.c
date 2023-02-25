/* A program that approximates the value of Euler's number
by using a loop that terminates when the difference between
two successive values of e differ by less than 0.0000001.

e = 1 + (1/1!) + (1/2!) + (1/3!) + ... + (1/(n-1)!) + (1/n!)

PSEUDOCODE
initialize n to 3
initialize d to 1 + (1/1!)
initialize e to d + (1/2!)
while (e - d) >= 0.0000001
    d = e
    e = d + (1+n!)
    n++
print e

*/

#include <stdio.h>
#include <math.h>

int main (void)
{
    float d, e;
    int n = 3;

    //set d to 1 + (1/1!) = 2
    d = 2.0;
    //set e to d + (1/2!)
    e = 2.0;
    e = d + (1.0 / e);

    while (e - d >= 0.0000001)
    {
        d = e;
        e = 1.0;

        for (int i = 1; i <= n; i++)
            e *= i;

        e = d + (1 / e);
        n++;
    }

    printf ("\n\tThe value of e is %f.\n", e);

    return 0;
}
