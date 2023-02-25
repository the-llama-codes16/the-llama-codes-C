/* A program that tests the value of num1.
If num1 is 10, square num1.
If num1 is 9, read a new value into num1.
If it is 2 or 3, multiply num1 by 99 and print out
the result.
Implement the code in switch statements */

#include <stdio.h>

int main (void)
{
    int num1;
    double num2;

    printf ("Enter a number: ");
    scanf ("%d", &num1);

    switch (num1)
        {
            case 10:
                num2 = pow (num1, 2);
                printf ("%.2lf\n", num2);
                break;

            case 9:
                 printf ("\nEnter a new number: ");
                 scanf ("%d", &num1);

                 switch (num1)
                    {
                    case 10:
                        num2 = pow (num1, 2);
                        printf ("%.2lf\n", num2);
                        break;

                    case 2:
                    case 3:
                        num1 = num1 * 99;
                        printf ("%d\n", num1);
                        break;
                    }//switch if num1 is 9
                 break;
        }//switch for num1

    return 0;
}
