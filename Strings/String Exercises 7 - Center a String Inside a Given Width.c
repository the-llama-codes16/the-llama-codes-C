/* A program that has a function that, given a string, a width,
and an empty string for output, centers the string in the output
area. */


#include <stdio.h>
#include <string.h>

#define FLUSH while (getchar() != '\n')

void centerTheString (char strInput[], int InputStrLen, int outWidth);

int main (void) {
    char strInput[81];
    int outWidth;

    printf("\nThis program asks you for a string and a width, and centers the string with the output width.");
    printf("\nPlease enter the string (Max 80 characters): ");
    scanf("%80[^\n]", strInput);
    FLUSH;
    printf("Please enter the output width (Max 80): ");
    scanf("%d", &outWidth);

    //validating the inputs
    int InputStrLen = strlen(strInput);
    if (outWidth > 80)
        outWidth = 80;
    if (outWidth < InputStrLen) {
        printf("Output width cannot be smaller than string length.\n");
        exit(1);
    }

    printf("\nYou entered:\nString: %s\nWidth: %d", strInput, outWidth);

    centerTheString(strInput, InputStrLen, outWidth);
    FLUSH;
    printf("\nResult -> |%s|\n", strInput);

    return 0;
}//main


void centerTheString (char strInput[], int InputStrLen, int outWidth) {
    int LeadSpace = (outWidth - InputStrLen) / 2;
    if (LeadSpace == 0)
        LeadSpace = 1;

    //Moving the characters to center them and adding leading spaces
    for (int index = InputStrLen - 1; index >= 0; index--) {
        strInput[index + LeadSpace] = strInput[index];
        strInput[index] = ' ';
    }

    //Adding the trailing spaces
    int ctr;
    for (ctr = InputStrLen + LeadSpace; ctr <= outWidth - 1; ctr++){
        strInput[ctr] = ' ';
    }

    strInput[ctr] = '\0';

    return;
}//CenterTheString


