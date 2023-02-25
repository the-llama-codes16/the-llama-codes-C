/* A program to calculate and print the next two numbers
in each of the following series using only one variable in each.
a. 0,5,10,15,20,25,?,?
b. 0,2,4,6,8,10,?,?
c. 1,2,4,8,16,32,?,? */

#include<stdio.h>

int main(void)
{
    int a,b,c;

    //For problem a
    printf("0,5,10,15,20,25,");
    a=30;
    printf("%d,", a);
    a+=5;
    printf("%d",a);

    /*For problem a USING LOOP
    printf("\n0,5,10,15,20,25");
    a=25;
    for (int i=0; i<2; i++)
    {
        printf(",");
        a+=5;
        printf("%d",a);
    }*/


    //For problem b
    printf("\n0,2,4,6,8,10,");
    b=12;
    printf("%d,",b);
    b+=2;
    printf("%d",b);


    //For problem c
    printf("\n1,2,4,8,16,32,");
    c=32*2;
    printf("%d,",c);
    c*=2;
    printf("%d",c);

    return 0;
}

