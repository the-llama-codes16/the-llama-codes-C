/* A program that tests a user-entered character and
displays its classification according to the ASCII
Classifications of character type. */

#include <stdio.h>
#include <ctype.h>

char getData (void);
void classChar (char input);

int main (void)
{
    char input = 0;

    input = getData ();
    //printf ("\n*** data from getData: %c\n", input);

    classChar (input);

    return 0;
}//main


char getData (void)
{
    char input;

    printf ("\n\tThis program determines the classification of a character.");
    printf ("\n\tPlease enter a character: ");
    scanf ("%c", &input);

    return input;
}//getData


void classChar (char input)
{
    if (isprint (input))
    {
        printf ("\n\t \"%c\" is a printable", input);

        if (isspace (input))
        {
            printf (", space");
        }
        else
        {
            printf (", graphical");

            if (ispunct (input))
            {
                printf (", punctuation");
            }
            else
            {
                printf (", alphanumeric");

                if (isdigit (input))
                {
                    printf (", digit");
                }
                else
                {
                    printf (", alphabetic");

                    if (isupper (input))
                        printf (", uppercase");
                    else
                        printf (", lowercase");
                }
            }
        }
    }
    else
        printf ("\n\t \"%c\" is a control", input);

    printf (" character.\n");

    return ;
}//clasChar

