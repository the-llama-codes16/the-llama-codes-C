/* A function that accepts a string (pointer to a character)
and deletes the last character by moving the null character
one position to the left. */

#include <stdio.h>
#include <string.h>

#define FLUSH while (getchar() != '\n')

void deleteLastChar (char strInput[]);

int main (void) {
    char strInput[81];

    printf("\nThis program accepts a string and removes its last character.");
    printf("\nEnter string (Maximum of 80 characters): ");
    fgets(strInput, 81, stdin);

    deleteLastChar(strInput);
    printf("Result -> %s\n", strInput);

    return 0;
}//main


void deleteLastChar (char strInput[]) {
    // Removes the last character of the string
    char* nullPtr;
    char* lastCharPtr;

    nullPtr = strrchr(strInput, '\0');
    lastCharPtr = nullPtr - 2;
    //count 2 steps back instead of 1 because fgets does not remove newline character
    *lastCharPtr = '\0';

    return;
}
