/* A program that converts degrees into radians */

#include<stdio.h>
#include<math.h>

int main(void)
{
    float deg, radi;

    printf("Enter angle in degrees: ");
    scanf("%f", &deg);

    radi = deg *(M_PI/180);
    printf("%.2f degrees is %f radians\n", deg,radi);

    return 0;
}
