/* A function that accepts a string and deletes the
first character */

#include <stdio.h>
#include <string.h>

void deleteFirstChar (char strInput[]);

int main (void) {
    char strInput[81];

    printf("\nThis is a program that deletes the first character of the string you give.\n");
    printf("Please enter a string (Max 80 characters): ");
    fgets(strInput, 81, stdin);

    deleteFirstChar(strInput);
    printf("Result -> %s", strInput);

    return 0;
}//main


void deleteFirstChar (char strInput[]) {
    int strLength;

    strLength = strlen(strInput);
    for (int ctr = 0; ctr <= strLength; ctr++) {
        strInput[ctr] = strInput[ctr + 1];
    }

    return;
}//deleteFirstChar
