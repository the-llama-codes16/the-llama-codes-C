/* A program that creates the structure presented below.

The program must read an integer into variable "a" and print
it using p, q, r, s, t, u, and v.

a = int variable
p = pointer to a
    q = pointer to p
    r = pointer to p
        s = pointer to q
        t = pointer to q
        u = pointer to r
        v = pointer to r

*/

#include <stdio.h>

int main (void) {
    int a;
    int* p = &a;
    int** q = &p;
    int** r = &p;
    int*** s = &q;
    int*** t = &q;
    int*** u = &r;
    int*** v = &r;

    printf ("\nPlease enter a number: ");
    scanf ("%d", &a);

    printf ("\nPrinting using p: %2d", *p);
    printf ("\nPrinting using q: %2d", **q);
    printf ("\nPrinting using r: %2d", **r);
    printf ("\nPrinting using s: %2d", ***s);
    printf ("\nPrinting using t: %2d", ***t);
    printf ("\nPrinting using u: %2d", ***u);
    printf ("\nPrinting using v: %2d\n\n", ***v);

    return ;
}
