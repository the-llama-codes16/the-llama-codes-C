/* A program that has a function that returns the number of times
the character is found in a string. The function has two parameters,
 a string and the character to be counted. */

#include <stdio.h>
#include <string.h>

#define FLUSH while (getchar() != '\n')

int countCharinStr (char strInput[], char charSearch);

int main (void) {
    char strInput[81];
    char charSearch;
    int charCount;

    printf("\nThis program returns the number of times a character appears in a string.");
    printf("\nPlease enter string (Max 80 characters):");
    scanf("%80[^\n]", strInput);
    FLUSH;
    printf("Please enter the character to be counted: ");
    scanf(" %c", &charSearch);
    printf("\nYou entered: \nString: %s\nCharacter: %c", strInput, charSearch);

    charCount = countCharinStr(strInput, charSearch);

    printf("\n%c appears %d time/s.\n", charSearch, charCount);

    return;
}//main


int countCharinStr (char strInput[], char charSearch) {
    int length = strlen(strInput);
    int charMatch = 0;

    for (int step = 0; step <= length; step++) {
        if (strInput[step] == charSearch){
            charMatch++;
        }
    }

    return charMatch;
}//countCharinStr

