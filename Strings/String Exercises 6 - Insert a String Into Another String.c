/* A program that has a function that inserts a string into
another string at a specified position. It returns a positive
number if the insertion is successful or 0 if it has any
problem, such as insertion location greater than the length of
the receiving string. The first parameter is the receiving string,
the second parameter is the string to be inserted, and the third
parameter is the insertion (index) position in the first string. */

#include <stdio.h>
#include <string.h>

#define FLUSH while (getchar() != '\n');

int insertString (char strInput[], char strInsert[], int insrtPt);

int main (void) {
    char strInput[81];
    char strInsert[81];
    int insrtPt;
    int successCheck;

    printf("\nThis program allows you to insert a string into another string in the location you prefer.");
    printf("\nPlease enter the main string (Max 40 characters): ");
    scanf("%80[^\n]", strInput);
    FLUSH;
    printf("Please enter the string to be inserted (Max 40 characters): ");
    scanf("%80[^\n]", strInsert);
    FLUSH;
    printf("Please enter the insertion position (index): ");
    scanf("%d", &insrtPt);

    printf("\nYou entered the following: ");
    printf("\nMain String: \"%s\"\nString to insert: \"%s\"\nInsertion Position: %d\n", strInput, strInsert, insrtPt);

    successCheck = insertString (strInput, strInsert, insrtPt);
    if (successCheck == 1) {
        printf("\nInsertion success.\nResult -> \"%s\"\n", strInput);
    }
    else {
        printf("\nInsertion failed. Please ensure that your inputs are valid and try again.\n");
    }

    return;
}//main


int insertString (char strInput[], char strInsert[], int insrtPt) {
    int strInputLen = strlen(strInput);
    int insrtLen = strlen(strInsert);
    int toMove = strInputLen - insrtPt;

    if (strInputLen + insrtLen + 1 > 81 || insrtPt < 0 || insrtPt > 80) {
        return 0;
    }

    //moving the characters after the insertion point
    for (int step = strInputLen + 1; step >= insrtPt; step--){
        strInput[step + insrtLen] = strInput[step];
    }

    //inserting the new string
    for (int ctr = 0; ctr < insrtLen; ctr++) {
        strInput[insrtPt + ctr] = strInsert[ctr];
    }

    return 1;
}





