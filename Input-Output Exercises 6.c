/* A program that prompts user for 3 numbers
then prints them in order and then reversed. */

#include <stdio.h>

int main(void)
{
    int a,b,c;

    printf("Enter 3 numbers:");
    scanf("%d %d %d",&a,&b,&c);

    printf("\nYour numbers forward:\n%d\n%d\n%d",a,b,c);
    printf("\n\nYour numbers reversed:\n%d\n%d\n%d",c,b,a);

    return 0;
}
