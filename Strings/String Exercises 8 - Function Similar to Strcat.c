/* A program that has a function called newStrCat that works the same
as the string library function strcat. */

#include <stdio.h>
#include <string.h>

#define FLUSH while (getchar() != '\n')

char* newStrCat (char* stringA, char* stringB);

int main (void) {
    char stringA[81];
    char stringB[81];
    int SpaceLeft;
    char* ResultStr;

    printf("\nThis program contains a function called newStrCat that performs the same as the string library function strcat.");
    printf("\nEnter a string(Max 80 characters): ");
    scanf("%80[^\n]", stringA);
    FLUSH;
    SpaceLeft = 80 - strlen(stringA);

    printf("Enter string to concatenate (press Enter if empty, Max %d characters): ", SpaceLeft);
    scanf("%[^\n]", stringB);
    FLUSH;
    if (strlen(stringB) > SpaceLeft) {
        printf("Input exceeded the maximum limit. Please try again.\n");
        exit(1);
    }

    ResultStr = newStrCat (stringA, stringB);
    printf("\nResulting String: %s\n", ResultStr);

    return 0;
}//main


char* newStrCat (char* stringA, char* stringB) {
    int toStrLen = strlen(stringA);
    int fromStrLen = strlen(stringB);

    int appendStart;
    int index;
    for (appendStart = toStrLen, index = 0; index < fromStrLen; appendStart++, index++) {
        stringA[appendStart] = stringB[index];
    }

    stringA[toStrLen + fromStrLen] = '\0';

    return (stringA);
}//newStrCpy














