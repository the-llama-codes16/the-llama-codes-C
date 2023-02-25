/* A program that generates a number from the set:
1, 2, 3, 4, 5, 6 */

#include<stdio.h>
#include<time.h>

int main(void)
{
    int choice;

    srand(time(NULL));

    choice = (rand() % 6) + 1;

    printf("A number from 1 to 6: %d\n\n", choice);

    return 0;
}
