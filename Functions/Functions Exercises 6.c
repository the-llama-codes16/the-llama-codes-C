/* A program that reads 3 integers and then prints them in the order
read and reversed. One function reads the data, one prints them, and one
prints them reversed */

#include<stdio.h>

void reader(int* f, int* s, int* t);
void printer(int* f, int* s, int* t);
void printrev(int* f, int* s, int* t);

int main (void)
{
    int a,b,c;

    reader(&a, &b, &c);
    printer(&a, &b, &c);
    printrev(&a, &b, &c);

    return 0;
}

//**********reader**************
void reader(int* f, int* s, int* t)
{
    printf("Please enter 3 integers: ");
    scanf("%d %d %d", f, s, t);

    return;
}

//**********printer**************
void printer(int* f, int* s, int* t)
{
    printf("\n\nThe three numbers are: \n%d %d %d", *f, *s, *t);

    return;
}

//**********printrev************
void printrev(int* f, int* s, int* t)
{
    printf("\n\nThe numbers reversed are: \n%d %d %d\n\n", *t, *s, *f);

    return;
}
