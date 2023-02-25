/* A program that determines a student's grade. It reads
three scores (between 0 to 100) and calls a function
that calculates and returns a student's grade based on the
following rules:

a. If the average score is 90 or more, the grade is A.

b. If the average score is 70 or more and less than 90, it
checks the third score. If the third score is more than 90,
the grade is A. Otherwise, the grade is B.

c. If the average score is 50 or more and less than 70, it
checks the average of the second and third scores. If the
average of the two is greater than 70, the grade is C. Otherwise,
it is D.

d. If the average score is less than 50, then the grade is F.

The program's main is to contain only call statements. At least
three subfunctions are required: one to read scores, one to
determine the grade, and one to print the results. */


#include <stdio.h>

void getScores (float* fscore, float* sscore, float* tscore);
char grader (float fscore, float sscore, float tscore);
float calcAve (float fscore, float sscore, float tscore);
void printRes (char grade);

int main (void)
{
    float fscore, sscore, tscore;
    float ave;
    char grade;

    getScores (&fscore, &sscore, &tscore);
   // printf ("\n***data from getScores: %f %f %f\n", fscore, sscore, tscore);
    grade = grader (fscore, sscore, tscore);
    //printf ("\n***data from grader: %c\n", grade);
    printRes (grade);

    return 0;
}//main


void getScores (float* fscore, float* sscore, float* tscore)
{
    printf ("\n\tPlease enter 3 scores separated by spaces: ");
    scanf ("%f %f %f", fscore, sscore, tscore);

    return;
}//getScores


char grader (float fscore, float sscore, float tscore)
{
    float ave;
    char grade;

    ave = calcAve (fscore, sscore, tscore);
    //printf ("\n****result from calcAve: %f\n", ave);

    if (ave >= 90)
        grade = 'A';
    else if (ave >= 70)
    {
        if (tscore > 90)
            grade = 'A';
        else
            grade = 'B';
    }
    else if (ave >= 50)
    {
        float ave2;
        ave2 = (sscore + tscore) / 2.0;

        if (ave2 > 70)
            grade = 'C';
        else
            grade = 'D';
    }
    else
        grade = 'F';

    return grade;
}//grader


float calcAve (float fscore, float sscore, float tscore)
{
    return ((fscore + sscore + tscore) / 3);
}


void printRes (char grade)
{
    printf ("\n\tYour grade is %c.\n\n", grade);

    return ;
}













