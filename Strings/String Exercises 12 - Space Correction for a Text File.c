/* Today's spelling checks do more than simply test for correctly spelled words.
They also verify common punctuation. For example, a period must be followed by only
one space. Write a program that reads a text file and removes extra spaces after a
period, a comma, semicolon, or colon. Write the corrected text to a new file.

Print your test data before and after they are run through your program.

*/

#include<stdio.h>
#include<string.h>

#define FLUSH while(getchar() != '\n')

void CopyFileContent (FILE* fhand, char rawString[]);
void SpaceCorrect (char rawString[], char cleanString[]);

int main (void) {
    char fname[51] = "";
    char rawString[300] = "";
    char cleanString[300] = "";
    FILE* fhand;
    int write;

    //get file name
    printf("\nEnter file name with extension: ");
    scanf("%50[^\n]", fname);
    FLUSH;

    //verify if file exists
    fhand = fopen(fname, "r");
    if (fhand == NULL) {
        printf("File cannot be opened. Please try again.\n");
        exit(1);
    }

    //copy file content to string and print
    CopyFileContent(fhand, rawString);
    printf("\nContents of %s:\n\"%s\"", fname, rawString);

    //correct the string
    SpaceCorrect(rawString, cleanString);

    //display corrected string and write to a new file
    printf("\nCorrected:\n\"%s\"\n", cleanString);
    fhand = fopen("Corrected.txt", "w");
    write = fputs(cleanString, fhand);
    if (write == EOF) {
        printf("\nWriting corrected string failed. Please try again.\n");
        exit(1);
    }
    else {
        printf("\nCorrected string has been written to Corrected.txt. Please verify by opening the file.\n");
    }
    return 0;
}//main


void CopyFileContent (FILE* fhand, char rawString[]) {
    fgets(rawString, 300, fhand);
}//CopyFileContent


void SpaceCorrect (char rawString[], char cleanString[]) {
    int rawStrLen = strlen(rawString);
    int cleanIndex;
    int rawIndex;
    int signal = 0;

    for (cleanIndex = 0, rawIndex = 0; rawIndex < rawStrLen; cleanIndex++, rawIndex++) {
        if (signal == 1) {
            while (rawString[rawIndex] == ' ') {
                rawIndex++;
            }
            signal = 0;
        }

        cleanString[cleanIndex] = rawString[rawIndex];

        if (rawString[rawIndex] == '.' || rawString[rawIndex] == ',' || rawString[rawIndex] == ':' || rawString[rawIndex] == ';') {
            signal = 1;
            cleanIndex++;
            cleanString[cleanIndex] = ' ';
        }

    }
}//SpaceCorrect
