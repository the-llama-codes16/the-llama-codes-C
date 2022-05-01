/* A program that creates the following structure:

a = int variable
x = pointer to a

b = int variable
p = pointer to b
y = pointer to p

c = int variable
q = pointer to c
r = pointer to q
z = pointer to r

The program reads the value for a and b using x and y.
The program then multiplies the value of a and b and stores
the result to c using the pointers x, y, and z.
Finally, it prints all three variables using pointers x, y, and z.

*/

#include <stdio.h>

int main (void) {
    int a;
    int* x = &a;

    int b;
    int* p = &b;
    int** y = &p;

    int c;
    int* q = &c;
    int** r = &q;
    int*** z = &r;

    printf ("\nPlease enter 2 numbers: ");
    scanf ("%d%d", x, *y);

    ***z = (*x) * (**y);

    printf ("\nPrinting...");
    printf ("\na using x: %d", *x);
    printf ("\nb using y: %d", **y);
    printf ("\nc using z: %d\n", ***z);

    return 0;
}
