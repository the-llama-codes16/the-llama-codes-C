/* A program that follows a given pseudocode:
1. Prompt the user to enter a number
2. Read number
3. Display number
4. Get a random number and scale to range 3..37
5. Display random number
6. Set product to number * random number
7. Display product
8. Display ceiling of random number
9. Display floor of product
10. Display number raised to power of random number
11. Display square root of random number */


#include <stdio.h>
#include <time.h>

int main (void)
{
    int inpnum;
    int randnum;
    int prod;

    printf ("Please enter number: ");
    scanf ("%d", &inpnum);
    printf ("Number: %d", inpnum);

    srand (time(NULL));

    randnum = (rand() % 35) + 3;
    printf ("\nRandom Number: %d", randnum);

    prod = inpnum * randnum;
    printf ("\nProduct: %d", prod);

    printf ("\nCeiling of random number: %lf", ceil(randnum));
    printf ("\nFloor of product: %lf", floor (prod));
    printf ("\nNumber raised to the random number: %lf", pow(inpnum,randnum));
    printf ("\nSquare root of random number: %lf", sqrt(randnum));

    return 0;
}
