/* A program that adds, subtracts, multiplies and divides
2 numbers using pointers. */

#include <stdio.h>

int main (void) {
    int a;
    int b;
    int r;
    int* pa = &a;
    int* pb = &b;
    int* pr = &r;

    printf ("\nPlease enter two numbers: ");
    scanf ("%d%d", pa, pb);

    *pr = *pa + *pb;
    printf ("\n%d + %d = %d", *pa, *pb, *pr);

    *pr = *pa - *pb;
    printf ("\n%d - %d = %d", *pa, *pb, *pr);

    *pr = *pa * *pb;
    printf ("\n%d * %d = %d", *pa, *pb, *pr);

    *pr = *pa / *pb;
    printf ("\n%d / %d = %d\n", *pa, *pb, *pr);

    return 0;
}
