/* Playing with void pointer type.

The program prompts the user to enter a character,
an integer, a long integer, and a floating-point number. The
program then calls a print function that only accepts a void
pointer variable as a parameter. Using the void pointer, print
the data by casting appropriately.

*/

#include <stdio.h>

int main (void) {
    int intData;
    char charData;
    long int longData;
    float floatData;
    void* pVoid;

    printf ("\nPlaying with pointers.");
    printf ("\nPlease enter an integer: ");
    scanf ("%d", &intData);
    printf ("Please enter a character: ");
    scanf (" %c", &charData);
    printf ("Please enter a long integer: ");
    scanf ("%d", &longData);
    printf ("Please enter a floating-point number: ");
    scanf ("%f", &floatData);

    printf ("\n\nPrinting all data using a void pointer...");
    printf ("\nPrinting data at location: %p", pVoid);
    pVoid = &intData;
    printf ("\nInteger: %d", *((int*) pVoid));
    pVoid = &charData;
    printf ("\nCharacter: %c", *((char*) pVoid));
    pVoid = &longData;
    printf ("\nLong Integer: %d", *((int*) pVoid));
    pVoid = &floatData;
    printf ("\nFloating-point Number: %.2f\n", *((float*) pVoid));

    return 0;
}
