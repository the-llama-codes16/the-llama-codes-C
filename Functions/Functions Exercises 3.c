/* A program that generates a number from the set:
1, 4, 7, 10, 13, 16 */

#include<stdio.h>
#include<time.h>

int main(void)
{
    int numpick;

    int choice[6];
    choice[0] = 1;
    choice[1] = 4;
    choice[2] = 7;
    choice[3] = 10;
    choice[4] = 13;
    choice[5] = 16;

    srand(time(NULL));

    numpick = rand() % 6;

    printf("A number from the given choices: %d \n\n", choice[numpick]);

    return 0;
}
