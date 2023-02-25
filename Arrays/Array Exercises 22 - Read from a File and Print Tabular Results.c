/* A program that keeps records and performs statistical analysis
for a class of students. The class may have up to 40 students. There
are five quizzes during the term. Each student is identified by a
four-digit student number.

The program will print the student scores and calculate and print
the statistics for each quiz. The output is in the same order as
the input; no sorting is needed. The input will be read from a text file.
*/

#include <stdio.h>
#include <stdlib.h>

int main (void) {
    FILE* quizsheet;
    int numstud;

    printf ("\nInput number of students (Max 40): ");
    scanf ("%d", &numstud);
    if (numstud > 40) {
        numstud = 40;
    }

    char student [numstud];
    char quiz1 [numstud];
    char quiz2 [numstud];
    char quiz3 [numstud];
    char quiz4 [numstud];
    char quiz5 [numstud];

    quizsheet = fopen ("Student Quiz Scores (for Array Exercises 22).txt", "r");
    if (quizsheet == NULL) {
        printf ("File cannot be opened.\n");
        return 0;
    }
    else {
        printf ("File can be opened. \n\n");
    }

    printf ("Student    Quiz 1    Quiz 2    Quiz 3    Quiz 4    Quiz 5\n");

    while (fscanf (quizsheet, "%s %s %s %s %s %s", student, quiz1, quiz2, quiz3, quiz4, quiz5) == 1) {
        printf ("%s %s %s %s %s %s\n", student, quiz1, quiz2, quiz3, quiz4, quiz4, quiz5);
    }

    return 0;
}
