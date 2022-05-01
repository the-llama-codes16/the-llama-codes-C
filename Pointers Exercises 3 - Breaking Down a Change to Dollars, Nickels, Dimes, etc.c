/* A function that receives a floating-point number
representing the change from a purchase. The function will
pass back the breakdown of the change in dollar bills,
half-dollars, quarters, dimes, nickels, and pennies.  */

#include <stdio.h>
#include <math.h>

float getData (void);
void breakDown (float change, int* dollar, int* halfdollar, int* quarter, int* dime, int* nickel, int* pennies);
void printRes (float change, int dollar, int halfdollar, int quarter, int dime, int nickel, int pennies);

int main (void) {
    float change;
    int dollar;
    int halfdollar;
    int quarter;
    int dime;
    int nickel;
    int pennies;

    change = getData ();
    breakDown (change, &dollar, &halfdollar, &quarter, &dime, &nickel, &pennies);
    printRes (change, dollar, halfdollar, quarter, dime, nickel, pennies);

    return 0;
}//main


float getData (void) {
    float input;

    printf ("\nThis program receives an amount you got as change and returns a breakdown.");
    printf ("\nPlease input amount: ");
    scanf ("%f", &input);

    return input;
}//getData


void breakDown (float change, int* dollar, int* halfdollar, int* quarter, int* dime, int* nickel, int* pennies) {
    *dollar = change / 1;
    change = change - *dollar;

    *halfdollar = change / 0.5;
    change = change - (*halfdollar * 0.5);

    *quarter = change / 0.25;
    change = change - (*quarter * 0.25);

    *dime = change / 0.10;
    change = change - (*dime * 0.10);

    *nickel = change / 0.05;
    change = change - (*nickel * 0.05);

    *pennies = change / 0.01;

    return ;
}//breakDown


void printRes (float change, int dollar, int halfdollar, int quarter, int dime, int nickel, int pennies) {
    printf ("\nYour change is %f.\nBreakdown:\n", change);
    printf ("%2d dollar/s\n", dollar);
    printf ("%2d half-dollar/s\n", halfdollar);
    printf ("%2d quarter/s\n", quarter);
    printf ("%2d dime/s\n", dime);
    printf ("%2d nickel/s\n", nickel);
    printf ("%2d penny/ies\n\n", pennies);

    return ;
}//printRes
