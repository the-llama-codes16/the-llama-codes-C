/* A program that has a function that accepts a string
and deletes all the leading spaces. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FLUSH while (getchar() != '\n')

void delLeadSpace (char strInput[]);

int main (void) {
    char strInput[81];

    printf("\nThis program accepts a string and deletes all leading whitespaces.");
    printf("\nPlease enter a string (Max 80 characters): ");
    scanf("%80[^\n]", strInput);
    FLUSH;

    printf("\nYou entered: \"%s\"", strInput);

    delLeadSpace(strInput);
    printf("\nResult -> \"%s\"\n", strInput);

    return 0;
}//main


void delLeadSpace (char strInput[]) {
    char* ptrLastLeadSpace;
    int LeadSpaceCount;
    int length = strlen(strInput);

    //check if there is any leading whitespace
    if (strInput[0] == '\n' || strInput[0] == '\t' || strInput[0] == ' ') {
        ptrLastLeadSpace = &strInput[0];
    }
    else {
        return;
    }

    //check if more whitespace follows and save the location of the last leading whitespace
    while (*(ptrLastLeadSpace + 1) == '\n' || *(ptrLastLeadSpace + 1) == '\t' || *(ptrLastLeadSpace + 1) == ' '){
        ptrLastLeadSpace += 1;
    }

    //delete the whitespace characters by replacing them with the string starting with a non-whitespace character
    LeadSpaceCount = ptrLastLeadSpace - &strInput[0] + 1;

    for (int count = 0; count<= length - LeadSpaceCount; count++) {
        strInput[count] = strInput[count + LeadSpaceCount];
        strInput[count + LeadSpaceCount] = '\0';

    }

    return;
}//delLeadSpace
