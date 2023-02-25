/*  A program that follows the structure below.

a, b, c = int variables
p = pointer to a
q = pointer to b
r = pointer to c

The program must read input from user using p, q, and r.

*/

#include <stdio.h>

int main (void) {
    int a;
    int b;
    int c;
    int* p = &a;
    int* q = &b;
    int* r = &c;

    printf ("\nThis program aims to read input using pointers.");
    printf ("\nPlease enter first number (for a): ");
    scanf ("%d", p);
    printf ("Please enter second number (for b): ");
    scanf ("%d", q);
    printf ("Please enter third number (for c): ");
    scanf ("%d", r);

    printf ("\n\na: %d", a);
    printf ("\nb: %d", b);
    printf ("\nc: %d", c);
    printf ("\na using p: %d", *p);
    printf ("\nb using q: %d", *q);
    printf ("\nc using r: %d\n\n", *r);

    printf ("Reassignment..\np = &c\nq = &a\nr = &b\n");
    p = &c;
    q = &a;
    r = &b;
    printf ("a using q: %d", *q);
    printf ("\nAddress of q: %p", &q);
    printf ("\nb using r: %d", *r);
    printf ("\nAddress of r: %p", &r);
    printf ("\nc using p: %d", *p);
    printf ("\nAddress of p: %p\n", &p);

    return 0;
}
