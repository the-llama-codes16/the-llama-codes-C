/* A program that prompts user for 9 integers
and prints them three in a line separated by commas */

#include <stdio.h>

int main(void)
{
    int a,b,c,d,e,f,g,h,i;

    printf("Input 9 numbers:");
    scanf("%d %d %d %d %d %d %d %d %d",&a,&b,&c,&d,&e,&f,&g,&h,&i);

    printf("\nOutput:");
    printf("\n%2d, %2d, %2d",a,b,c);
    printf("\n%2d, %2d, %2d",d,e,f);
    printf("\n%2d, %2d, %2d",g,h,i);

    return 0;
}
