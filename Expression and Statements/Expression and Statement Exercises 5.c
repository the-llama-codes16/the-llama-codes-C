/* A program that calculates the area and perimeter of a rectangle
from a user-supplied length and width */

#include<stdio.h>

int main(void)
{
    float length, width, area, perimeter;

    printf("Enter length of rectangle: ");
    scanf("%f", &length);

    printf("Enter width of rectangle: ");
    scanf("%f", &width);

    area = length*width;
    perimeter = 2 * (length+width);

    printf("\nThe area of the rectangle is %.2f.", area);
    printf("\nThe perimeter of the rectangle is %.2f.", perimeter);

    return 0;
}
