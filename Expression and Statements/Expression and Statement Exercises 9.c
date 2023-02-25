/* A program showing the C codes for the following formulas:
a. KinEn = (mv^2)/2
b. res = (b+c)/2bc
Assume all variables are defined as double. */

#include<stdio.h>

int main(void)
{
    double KinEn, m, v;
    double res, b, c;

    printf("Enter values for mass and velocity: ");
    scanf("%lf %lf", &m, &v);
    KinEn = (m * (v*v))/2;
    printf("\nKinetic Energy: %lf", KinEn);

    printf("\n\nEnter values for b and c: ");
    scanf("%lf %lf", &b, &c);
    res = (b+c) / (2*b*c);
    printf("\nRes: %lf", res);

    return 0;
}
