/* A program that prompts user for an integer
in the range 0 to 32,767 then prints the digits accordingly.
Example of output when the number entered is 1234:
0   1   2   3   4
1   2   3   4
2   3   4
3   4
4
*/

#include<stdio.h>

int main(void)
{
    int number;
    int first,second,third,fourth,fifth;

    printf("Please enter a number from 0 to 32,767: ");
    scanf("%d", &number);

    first = number/10000;
    second = (number/1000) % 10;
    third = ((number/100) % 100) % 10;
    fourth = ((((number/10) % 1000) % 100) % 10);
    fifth = ((((number%10000) % 1000) % 100) % 10);

    printf("\n\n\t%d%3d%3d%3d%3d",first,second,third,fourth,fifth);
    printf("\n\t%d%3d%3d%3d", second,third,fourth,fifth);
    printf("\n\t%d%3d%3d",third,fourth,fifth);
    printf("\n\t%d%3d",fourth,fifth);
    printf("\n\t%d",fifth);

    return 0;
}
