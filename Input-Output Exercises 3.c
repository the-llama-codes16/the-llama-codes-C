/*A program that prompts user for an integer and then prints
the input as a character, integer, and float*/

#include <stdio.h>
int main (void)
{
    int input;

    printf("Enter an integer:");
    scanf("%d", &input);

    printf("\nThe number as a character: %c", input);
    printf("\nThe number as a decimal: %d", input);
    printf("\nThe number as a float: %f", input);

    return 0;

}
