/* A string is a Palindrome if it can be read forward and backward with the
same meaning. Capitalization and spacing are ignored. For example, "anna" and
"go dog" are palindromes. Write a function that accepts a string and returns
true if the string is a palindrome and false if it is not. Test your function
with the following two palindromes and at least one case that is not a palindrome:

Madam, I'm Adam
Able was I ere I saw Elba
*/

#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

#define FLUSH while(getchar() != '\n')

bool isStrPalindrome (char strInput[]);

int main (void) {
    char strInput[81];
    bool isPalindrome;

    printf("\nThis program checks if the string you enter is a Palindrome.");
    printf("\nPlease enter a string (Max 80 chars): ");
    scanf("%80[^\n]", strInput);
    FLUSH;

    isPalindrome = isStrPalindrome(strInput);

    if (isPalindrome == true)
        printf("--> a Palindrome\n");
    else if (isPalindrome == false)
        printf("--> not a Palindrome\n");

    return 0;
}//main


bool isStrPalindrome (char strInput[]) {
    int strInputLen = strlen(strInput);
    char StartEnd[80] = "\0";
    char EndStart[80] = "\0";
    char charHolder;
    int compareRes;

    //looping through the string to form the filtered versions
    //for StartEnd
    int index = -1;
    for (int step = 0; step < strInputLen; step++) {
        charHolder = strInput[step];
        if (isalpha(charHolder) != 0) {
            index++;
            charHolder = tolower(charHolder);
            StartEnd[index] = charHolder;
        }
    }

    //for EndStart
    index = -1;
    for (int step = strInputLen - 1; step >= 0; step--) {
        charHolder = strInput[step];
        if (isalpha(charHolder) != 0) {
            index++;
            charHolder = tolower(charHolder);
            EndStart[index] = charHolder;
        }
    }

    //printf("\n%s\n%s\n", StartEnd, EndStart);

    compareRes = strcmp(StartEnd, EndStart);
    if (compareRes == 0)
        return true;
    else
        return false;
}//isStrPalindrome

