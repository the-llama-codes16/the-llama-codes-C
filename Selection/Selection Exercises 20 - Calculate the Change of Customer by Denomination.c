/* A program that calculates the change due a
customer by denomination (pennies, nickels, dimes, etc).
The input has to be the purchase price and the size
of the bill tendered by the customer ($100, $50, $20,
$10, $5, $1).*/

#include <stdio.h>

void getData (float* price, int* hundred, int* fifty, int* twenty, int* ten, int* five, int* one);
void calcBills (float price, int hundred, int fifty, int twenty, int ten, int five, int one, int* paid, float* change, int* chundred, int* cfifty, int* ctwenty, int* cten, int* cfive, int* cone);
void calcCoins (float change, int* cpenny, int* cnickel, int* cdime, int* cquarter);
void printRes (float price, int paid, float change, int chundred, int cfifty, int ctwenty, int cten, int cfive, int cone, int cpenny, int cnickel, int cdime, int cquarter);


int main (void)
{
    float price, change;
    int paid;
    int hundred, fifty, twenty, ten, five, one;
    int chundred, cfifty, ctwenty, cten, cfive, cone;
    int cpenny, cnickel, cdime, cquarter;

    getData (&price, &hundred, &fifty, &twenty, &ten, &five, &one);
    //printf ("\n *** data from getData: %.2f %d %d %d %d %d %d\n", price, hundred, fifty, twenty, ten, five, one);

    calcBills (price, hundred, fifty, twenty, ten, five, one, &paid, &change, &chundred, &cfifty, &ctwenty, &cten, &cfive, &cone);
    //printf ("\n *** data from calcBills: %d %d %d %d %d %d\n", chundred, cfifty, ctwenty, cten, cfive, cone);

    calcCoins (change, &cpenny, &cnickel, &cdime, &cquarter);
    //printf ("\n *** data from calcCoins: %d %d %d %d\n", cpenny, cnickel, cdime, cquarter);

    printRes (price, paid, change, chundred, cfifty, ctwenty, cten, cfive, cone, cpenny, cnickel, cdime, cquarter);

    return 0;
}//main


void getData (float* price, int* hundred, int* fifty, int* twenty, int* ten, int* five, int* one)
{
    printf ("\n\tPurchase price: ");
    scanf ("%f", price);

    printf ("\n\tDenomination of bills tendered by customer:");
    printf ("\n\t(Please enter number of pieces)");
    printf ("\n\t$ 100: ");
    scanf ("%d", hundred);

    printf ("\t$  50: ");
    scanf ("%d", fifty);

    printf ("\t$  20: ");
    scanf ("%d", twenty);

    printf ("\t$  10: ");
    scanf ("%d", ten);

    printf ("\t$   5: ");
    scanf ("%d", five);

    printf ("\t$   1: ");
    scanf ("%d", one);

    return ;
}//getData


void calcBills (float price, int hundred, int fifty, int twenty, int ten, int five, int one, int* paid, float* change, int* chundred, int* cfifty, int* ctwenty, int* cten, int* cfive, int* cone)
{
    int wholeChange;
    int remainder;

    //amount tendered and change
    *paid = (100 * hundred) + (50 * fifty) + (20 * twenty) + (10 * ten) + (5 * five) + (1 * one);
    *change = *paid - price;

    //integral part of change
    wholeChange = (int) *change;

    //number of bills for each denomination
    *chundred = wholeChange / 100;
    remainder = wholeChange % 100;

    *cfifty = remainder / 50;
    remainder = remainder % 50;

    *ctwenty = remainder / 20;
    remainder = remainder % 20;

    *cten = remainder / 10;
    remainder = remainder % 10;

    *cfive = remainder / 5;
    remainder = remainder % 5;

    *cone = remainder;

    return ;
}//calcBills


void calcCoins (float change, int* cpenny, int* cnickel, int* cdime, int* cquarter)
{
    int whole, cent;
    float fcent;

    whole = (int) change;
    fcent = (change - whole) * 100;
    cent = (int) fcent;

    //penny = 1, nickel = 5, dime = 10, quarter = 25
    *cquarter = cent / 25;
    cent = cent % 25;

    *cdime = cent / 10;
    cent = cent % 10;

    *cnickel = cent / 5;
    cent = cent % 5;

    *cpenny = cent;

    return ;
}//calcCoins


void printRes (float price, int paid, float change, int chundred, int cfifty, int ctwenty, int cten, int cfive, int cone, int cpenny, int cnickel, int cdime, int cquarter)
{
    printf ("\n\tPrice:           %.2f", price);
    printf ("\n\tAmount Tendered: %d", paid);
    printf ("\n\tChange:          %.2f", change);
    printf ("\n\tDenominations:");
    printf ("\n\t\t$ 100: %2d", chundred);
    printf ("\tc  1: %d", cpenny);
    printf ("\n\t\t$  50: %2d", cfifty);
    printf ("\tc  5: %d", cnickel);
    printf ("\n\t\t$  20: %2d", ctwenty);
    printf ("\tc 10: %d", cdime);
    printf ("\n\t\t$  10: %2d", cten);
    printf ("\tc 25: %d", cquarter);
    printf ("\n\t\t$   5: %2d", cfive);
    printf ("\n\t\t$   1: %2d\n", cone);

}//printRes
