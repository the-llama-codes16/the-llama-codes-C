/*A program that prompts user for a character, integer,
and floating-point number then prints all of it.*/

#include <stdio.h>
int main(void)
{
    char a;
    int b;
    float c;

    printf("Please enter a character:");
    scanf(" %c", &a);

    printf("\nPlease enter an integer:");
    scanf("%d", &b);

    printf("\nPlease enter a floating-point number:");
    scanf("%f", &c);

    printf("\n%c %d", a, a);
    printf("\n%d", b);
    printf("\n%.2f", c);

    return 0;
}
