/* A program that has a function that accepts a string
and deletes all the trailing spaces at the end of the
string. */

#include <stdio.h>
#include <string.h>

void delTrailSpace (char strInput[]);

int main (void)
{
    char* strInput[81];

    printf("\nThis program accepts a string and deletes all the trailing spaces at the end.");
    printf("\nPlease enter a string (Maximum 80 characters): ");
    fgets(strInput, 81, stdin);

    printf("\nYour input is: \"%s\"", strInput);
    delTrailSpace(strInput);
    printf("\nResult -> \"%s\"\n", strInput);

    return 0;
}//main


void delTrailSpace (char strInput[]) {
    /* Starts search of whitespaces from the end of the string and deletes them until a
    non-whitespace character is found */

    char* ptrFirstWSpace;

    ptrFirstWSpace = strpbrk(strInput,"\n");

    do {
        *ptrFirstWSpace = '\0';
        ptrFirstWSpace -= 1;
    } while (*ptrFirstWSpace == '\n' || *ptrFirstWSpace == '\t' || *ptrFirstWSpace == ' ');

   /* Alternative:
    while (*(ptrFirstWSpace - 1) == '\n' || *(ptrFirstWSpace - 1) == '\t' || *(ptrFirstWSpace - 1) == ' ') {
        *ptrFirstWSpace = '\0';
        ptrFirstWSpace -= 1;
    }
    *ptrFirstWSpace = '\0'; */

    return;
}//delTrailSpace







