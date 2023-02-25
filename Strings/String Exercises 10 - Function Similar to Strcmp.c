/* A program that has a function called newStrCmp that works the same
as the string library function strcmp. */

#include <stdio.h>
#include<string.h>

#define FLUSH while (getchar() != '\n')

int newStrCmp (char StringA[], char StringB[]);

int main (void) {
    char StringA[81];
    char StringB[81];
    int Result;

    printf("\nThis program has a function called newStrCmp that works the same as the string library function strcmp\nand will compare 2 strings for you.");
    printf("\nPlease enter String A (Max 80 chars): ");
    scanf("%80[^\n]", StringA);
    FLUSH;
    printf("Enter String B (Max 80 chars): ");
    scanf("%80[^\n]", StringB);
    FLUSH;

    printf("\nComparing...\n");

    Result = newStrCmp(StringA, StringB);
    //interpreting result
    if (Result < 0)
        printf("\nString A comes first.\n");
    else if (Result > 0)
        printf("\nString B comes first.\n");
    else
        printf("\nBoth strings are the same.\n");

    return 0;
}//main


int newStrCmp (char StringA[], char StringB[]) {
    int boundIndex = (strlen(StringA) > strlen(StringB)? strlen(StringB): strlen(StringA));
    int Result;

    for (int index = 0; index <= boundIndex; index++) {
        if (StringA[index] < StringB[index])
            Result = -1;
        else if (StringA[index] > StringB[index])
            Result = 1;
        else
            Result = 0;
    }

    return Result;
}
