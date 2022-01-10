/* A program that follows a given flowchart. */

#include <stdio.h>

int main (void)
{
    int x, y;
    float z;

    printf ("Enter x: ");
    scanf ("%d", &x);
    printf ("Enter y: ");
    scanf ("%d", &y);

    if (x > 0)
    {
        if (y > 0)
        {
            z = x;
            y = x + 1;
        }//if y>0

        else
        {
            z = y;
        }//if y !>0

        z = z + 1;
    }//if x>0

    else
    {
        y = x - 1;
        z = 2 * x;
    }//if x!>0

    printf ("\nx: %d", x);
    printf ("\ny: %d", y);
    printf ("\nz: %.2f\n", z);

    return 0;
}
