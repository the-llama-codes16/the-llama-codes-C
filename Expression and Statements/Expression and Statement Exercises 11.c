/* A program that converts and prints user-supplied
measurement in inches into foot, yard, centimeter, meter */

#include<stdio.h>

int main(void)
{
    float inch;
    float foot,yard,cm,meter;

    printf("Enter measurement in inches: ");
    scanf("%f", &inch);

    foot = inch/12;
    yard = (inch/12) / 3;
    cm = inch*2.54;
    meter = (inch/12) / 3.28;

    printf("\nFoot: %.2f", foot);
    printf("\nYard: %.2f", yard);
    printf("\nCentimeter: %.2f", cm);
    printf("\nMeter: %.2f", meter);

    return 0;
}
