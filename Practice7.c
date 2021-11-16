/* A program that prompts user for 10 integers
and then prints the outermost pair, the
2nd pair, and so forth */

#include <stdio.h>

int main(void)
{
    int a,b,c,d,e,f,g,h,i,j;

    printf("Please enter 10 numbers:");
    scanf("%d %d %d %d %d %d %d %d %d %d",&a,&b,&c,&d,&e,&f,&g,&h,&i,&j);

    printf("\nYour numbers are:");
    printf("\n\t%2d %2d",a,j);
    printf("\n\t%2d %2d",b,i);
    printf("\n\t%2d %2d",c,h);
    printf("\n\t%2d %2d",d,g);
    printf("\n\t%2d %2d",e,f);

    return 0;
}
