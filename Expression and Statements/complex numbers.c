#include<stdio.h>
#include<math.h>
#include<complex.h>
int main(void)
{
    float a,b;
    double complex c,d;

    //Ask for real and imaginary values
    printf("Please enter real number:\n");
    scanf("%f",&a);
    printf("Please enter imaginary number:\n");
    scanf("%f",&b);

    //Combine values
    c = a + (b*I);

    //Print info
    d=conj(c);
    printf("%f %f %f %f\n", creal(c), cimag(c), cabs(c), carg(c));
    printf("%f %f %f %f", creal(d), cimag(d), cabs(d), carg(d));

    return 0;
}
