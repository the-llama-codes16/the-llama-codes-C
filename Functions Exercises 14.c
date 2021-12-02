/* A program that asks for temperature in Centigrade and provides
equivalent temperature in Fahrenheit, then vice versa. Main function
should only have function calls. */

#include <stdio.h>

double askCen (void);
double CenToFah (double cenTemp);
void CenToFahPrint (double ctfres);
double askFah (void);
double FahToCen (double fahTemp);
void FahToCenPrint (double ftcres);

int main (void)
{
    double inCen = 0, outFah = 0;
    double inFah = 0, outCen = 0;

    inCen = askCen ();
    outFah = CenToFah (inCen);
    CenToFahPrint (outFah);

    inFah = askFah ();
    outCen = FahToCen (inFah);
    FahToCenPrint (outCen);

    return 0;
}

//*******************askCen*************************
double askCen (void)
{
    double inp = 0;

    printf("Please input temperature in Celsius Centigrade: ");
    scanf ("%lf", &inp);

    return inp;
}

//*******************CenToFah**********************
double CenToFah (double cenTemp)
{
    double resFah = 0;

    resFah = cenTemp + 10;
    resFah = (cenTemp * (9.0/5)) + 32;

    return resFah;
}

//*******************CenToFahPrint******************
void CenToFahPrint (double ctfres)
{
    printf ("Temperature in Fahrenheit: %lf\n", ctfres);

    return;
}

//*********************askFah*************************
double askFah (void)
{
    double in = 0;

    printf ("\nPlease input temperature in Fahrenheit: ");
    scanf ("%lf", &in);

    return in;
}

//**********************FahToCen***********************
double FahToCen (double fahTemp)
{

    double resCen = 0;

    resCen = (fahTemp - 32) * (100.0/180.0);

    return resCen;
}

//**********************FahToCenPrint********************
void FahToCenPrint (double ftcres)
{
    printf ("Temperature in Celsius Centigrade: %lf\n\n", ftcres);

    return;
}
