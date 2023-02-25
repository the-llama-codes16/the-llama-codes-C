/* A program that has a function called newStrCat that works the same
as the string library function strcpy. */

#include <stdio.h>
#include <string.h>

#define FLUSH while (getchar() != '\n')

char* newStrCpy (char toStr[], char fromStr[]);

int main (void) {
    char toStr[50] = "\0"; //String B
    char fromStr [] = "The quick brown fox jumps over the lazy dog."; // String A

    printf("\nThis program has a function that works similarly to the string library function strcpy.");
    printf("\n\nInitial values:\nString A: %s\nString B: %s\n", fromStr, toStr);
    printf("\nCopying String A to String B using newStrCpy...");

    newStrCpy(toStr, fromStr);

    printf("\n\nResulting values:\nString A: %s\nString B: %s\n", fromStr, toStr);

    return 0;
}//main


char* newStrCpy (char toStr[], char fromStr[]) {
    int fromStrLen = strlen(fromStr);

    for (int index = 0; index < fromStrLen; index++) {
        toStr[index] = fromStr[index];
    }

    return toStr;
}//newStrCpy


