/* A program that has add, subtract, multiply, divide,
and print results functions similar to a program previously
provided as an example in the lesson. The print results function
should use a switch statement to format the result as shown below:

operand operator operand = result
*/

#include <stdio.h>
#include <stdlib.h>

int menu (void);
void getData (float* a, float* b);
float calc (float a, float b, int operation);
float add (float a, float b);
float sub (float a, float b);
float mult (float a, float b);
float divi (float a, float b);
void printRes (float a, float b, int operation, float result);


int main (void)
{
    float a, b;
    int operation;
    float result;

    operation = menu ();
    if (operation < 1 || operation > 4)
    {
        printf ("\n\tInvalid input.\n");
        exit (1);
    }
    //printf ("\n***value from menu: %d\n", operation);

    getData (&a, &b);
    //printf ("\n***value from getData: %f %f\n", a, b);

    result = calc (a, b, operation);
    //printf ("\n***value from result: %f\n", result);

    printRes (a, b, operation, result);

    return 0;
}


//------------------------menu---------------------------------
int menu (void)
{
    int choice;

    printf ("\n\t*********************************************\n");
    printf ("\t*                   MENU                    *\n");
    printf ("\t*                                           *\n");
    printf ("\t*  1. ADD                                   *\n");
    printf ("\t*  2. SUBTRACT                              *\n");
    printf ("\t*  3. MULTIPLY                              *\n");
    printf ("\t*  4. DIVIDE                                *\n");
    printf ("\t*                                           *\n");
    printf ("\t*********************************************\n");

    printf ("\n\n\tPlease type your choice and press enter: ");
    scanf ("%d", &choice);

    return choice;
}//menu


//------------------------getData------------------------------
void getData (float* a, float* b)
{
    printf ("\n\tPlease enter two integer numbers: ");
    scanf ("%f %f", a, b);

    return ;
}//getData


//-------------------------calc-------------------------------
float calc (float a, float b, int operation)
{
    float result;

    switch (operation)
    {
        case 1:
            result = add (a, b);
            break;
        case 2:
            result = sub (a, b);
            break;
        case 3:
            result = mult (a, b);
            break;
        case 4:
            result = divi (a, b);
    }

    return result;
}//calc


//----------------------------add---------------------------
float add (float a, float b)
{
    return (a + b);
}


//----------------------------sub---------------------------
float sub (float a, float b)
{
    return (a - b);
}


//---------------------------mult---------------------------
float mult (float a, float b)
{
    return (a * b);
}


//---------------------------divi---------------------------
float divi (float a, float b)
{
    return (a / b);
}


//--------------------------printRes-------------------------
void printRes (float a, float b, int operation, float result)
{
    switch (operation)
    {
        case 1:
            printf ("\n\t%.3f + %.3f = %.3f\n", a, b, result);
            break;
        case 2:
            printf ("\n\t%.3f - %.3f = %.3f\n", a, b, result);
            break;
        case 3:
            printf ("\n\t%.3f * %.3f = %.3f\n", a, b, result);
            break;
        case 4:
            printf ("\n\t%.3f / %.3f = %.3f\n", a, b, result);
    }

    return ;
}



