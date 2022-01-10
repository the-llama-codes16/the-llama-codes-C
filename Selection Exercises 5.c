/* Rewriting a program with the following code fragment
to a switch statement:

if (ch == 'E' || ch == 'e')
    countE++;
else if (ch == 'A' || 'a')
    countA++;
else if (ch == 'I' || 'i')
    countI++;
else
    printf ("Error--Not A, E, or I\a\n");

*/


#include <stdio.h>

int main (void)
{
    char ch;
    int countE = 0, countA = 0, countI = 0;

    printf ("Enter A, E, or I: ");
    scanf (" %c", &ch);

    switch (ch)
        {
            case 'E':
            case 'e':
                countE++;
                break;

            case 'A':
            case 'a':
                countA++;
                break;

            case 'I':
            case 'i':
                countI++;
                break;

            default:
                printf ("\nError--Not A, E, or I\a\n");
        } //switch(ch)

    printf ("\ncountE: %d", countE);
    printf ("\ncountA: %d", countA);
    printf ("\ncountI: %d\n", countI);

    return 0;
}
