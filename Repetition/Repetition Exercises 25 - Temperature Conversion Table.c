/* A program that prints out a conversion table
for Celsius to Fahrenheit (0 to 100) and Fahrenheit
to Celsius (32 to 212). Separate functions will be used
for the conversions. The tables must fit into a standard
monitor display. */

#include <stdio.h>

void celToFah (void);
void fahToCel (void);

int main (void)
{
    celToFah ();
    fahToCel ();

    return 0;
}//main


void celToFah (void)
{
    int column = 0;
    float fah;

    printf ("CELSIUS TO FAHRENHEIT CONVERSION TABLE\n\n");

    for (int c = 0; c <= 7; c++)
        printf ("Celsius  Fahrenheit  ");

    printf ("\n");

    for (int i = 0; i <= 100; i++)
    {
        fah = (i * 1.8) + 32;

        if (column > 7)
        {
            printf ("\n");
            column = 0;
        }

        printf ("   %3d   %7.2f     ", i, fah);

        column++;

    }

    return ;
}//celToFah


void fahToCel (void)
{
    int column = 0;
    float cel;

    printf ("\n\nFAHRENHEIT TO CELSIUS CONVERSION TABLE\n\n");

    for (int c = 0; c <= 7; c++)
        printf ("Fahrenheit  Celsius  ");

    printf ("\n");

    for (int i = 32; i <= 212; i++)
    {
        cel = (i - 32) / 1.8;

        if (column > 7)
        {
            printf ("\n");
            column = 0;
        }

        printf ("   %3d    %7.2f    ", i, cel);

        column++;
    }

}//fahToCel

