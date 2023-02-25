/* This program calculates the sum, difference, product,
quotient, and modulus of two numbers. */

#include<stdio.h>

void getData(int* a, int* b);
int add(int a, int b);
void printResadd(int a, int b, int sum);
int sub(int a, int b);
void printRessub(int a, int b, int dif);
int mul(int a, int b);
void printResmul(int a, int b, int pro);
void divandrem(int a, int b, int* quo, int* rem);
void printResdiv(int a, int b, int quo, int rem);

int main(void)
{
    int a, b;
    int sum = 0;
    int dif = 0;
    int pro = 0;
    int quo = 0;
    int rem = 0;

    getData(&a, &b);
    sum = add(a,b);
    printResadd(a,b,sum);

    dif = sub(a,b);
    printRessub(a,b,dif);

    pro = mul(a,b);
    printResmul(a,b,pro);

    divandrem(a,b,&quo,&rem);
    printResdiv(a,b,quo,rem);

    return 0;
}

//***********getData***************
void getData(int* a, int* b)
{
    printf("Enter 2 numbers: ");
    scanf("%d %d", a, b);

    return;
}

//***********add*******************
int add(int a, int b)
{
    return (a+b);
}

//***********printResadd***********
void printResadd(int a, int b, int sum)
{
    printf("%4d  +  %4d = %4d", a,b,sum);
    return;
}

//********** sub*******************
int sub(int a, int b)
{
    return (a-b);
}

//***********printRessub***********
void printRessub(int a, int b, int dif)
{
    printf("\n\n%4d  -  %4d = %4d", a,b,dif);
    return;
}

//***********mul*******************
int mul(int a, int b)
{
    return (a*b);
}

//***********printResmul***********
void printResmul(int a, int b, int pro)
{
    printf("\n\n%4d  *  %4d = %4d", a,b,pro);
    return;
}

//***********divandrem*************
void divandrem(int a, int b, int* quo, int* rem)
{
    *quo = a/b;
    *rem = a%b;

    return;
}

//***********printResdiv***********
void printResdiv(int a, int b, int quo, int rem)
{
    printf("\n\n%4d  /  %4d = %4d", a,b,quo);
    printf("\n\n%4d  %%  %4d = %4d", a,b,rem);
    return;
}
