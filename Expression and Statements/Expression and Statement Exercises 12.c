/* A program that calculates and prints the next
3 numbers of the Fibonacci series given:
0, 1, 1, 2, 3, 5, 8, 13, 21, ... */

#include<stdio.h>

int main(void)
{
    int fibn1,fibn2,fibn3;

    fibn1 = 13+21;
    fibn2 = fibn1+21;
    fibn3 = fibn2+fibn1;

    printf("0, 1, 1, 2, 3, 5, 8, 13, 21, %d, %d, %d", fibn1, fibn2, fibn3);

    return 0;
}
