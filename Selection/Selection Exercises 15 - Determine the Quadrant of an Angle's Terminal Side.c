/* A program that determines the quadrant of the terminal
side of an angle given by the user.

Quadrant I: 0 < angle < 90
Quadrant II: 90 < angle < 180
Quadrant III: 180 < angle < 270
Quadrant IV: 270 < angle < 360


Note: I decided to add more specifications since my
learnings from my Analytic Geometry class makes me
want to be more specific XD

Positive X-axis: angle = 0 or 360
Negative X-axis: angle = 180
Positive Y-axis: angle = 90
Negative Y-axis: angle = 270

Angles greater than 360 will also be evaluated accordingly.
Negative angles will still commence at positive X-axis but
will move clockwise instead of counterclockwise, and will still
be evaluated accordingly.

Main function must only call statements.*/


#include <stdio.h>
#include <math.h>

float getAngle (void);
int calcTerm (float angle);
int calcTermPos (float angle);
int calcTermNeg (float angle);
void printRes (float angle, int term);

int main (void)
{
    float angle;
    int term;

    angle = getAngle ();
    //printf ("\n***data from getAngle: %f\n", angle);
    term = calcTerm (angle);
    //printf ("\n***data from calcTerm: %f\n", term);
    printRes (angle, term);

    return 0;
}//main


float getAngle (void)
{
    float angle;

    printf ("\n\tThis program will determine what Quadrant or Axis your angle will terminate in.");
    printf ("\n\tPlease enter angle: ");
    scanf ("%f", &angle);

    return angle;
}//getAngle


int calcTerm (float angle)
{
    int term;

    if (angle >= 0)
        term = calcTermPos (angle);
    else
        term = calcTermNeg (angle);

    //printf ("\n***data from calcTermPos or Neg: %d\n", term);
    return term;
}//calcTerm


int calcTermPos (float angle)
{
    int term;
    int whole;
    float dec;

    if (angle > 360)
    {
        whole = (int) angle;
        dec = angle - whole;
        angle = whole % 360;
        angle = angle + dec;
    }

    if (angle == 0 || angle == 360)
        term = 1;
    else if (angle > 0 && angle < 90)
        term = 2;
    else if (angle == 90)
        term = 3;
    else if (angle > 90 && angle < 180)
        term = 4;
    else if (angle == 180)
        term = 5;
    else if (angle > 180 && angle < 270)
        term = 6;
    else if (angle == 270)
        term = 7;
    else if (angle > 270 && angle < 360)
        term = 8;

    return term;
}//calcTermPos


int calcTermNeg (float angle)
{
    int term;
    int whole;
    float dec;

    angle = fabs (angle);

    if (angle > 360)
    {
        whole = (int) angle;
        dec = angle - whole;
        angle = whole % 360;
        angle = angle + dec;
    }

    if (angle == 360)
        term = 1;
    else if (angle > 0 && angle < 90)
        term = 8;
    else if (angle == 90)
        term = 7;
    else if (angle > 90 && angle < 180)
        term = 6;
    else if (angle == 180)
        term = 5;
    else if (angle > 180 && angle < 270)
        term = 4;
    else if (angle == 270)
        term = 3;
    else if (angle > 270 && angle < 360)
        term = 2;

    return term;
}//calcTermNeg


void printRes (float angle, int term)
{
    switch (term)
    {
        case 1:
            printf ("\n\tThe given angle %.3f terminates in the positive X axis.\n", angle);
            break;
        case 2:
            printf ("\n\tThe given angle %.3f terminates in Quadrant I.\n", angle);
            break;
        case 3:
            printf ("\n\tThe given angle %.3f terminates in the positive Y axis.\n", angle);
            break;
        case 4:
            printf ("\n\tThe given angle %.3f terminates in Quadrant II.\n", angle);
            break;
        case 5:
            printf ("\n\tThe given angle %.3f terminates in the negative X axis.\n", angle);
            break;
        case 6:
            printf ("\n\tThe given angle %.3f terminates in Quadrant III.\n", angle);
            break;
        case 7:
            printf ("\n\tThe given angle %.3f terminates in the negative Y axis.\n", angle);
            break;
        case 8:
            printf ("\n\tThe given angle %.3f terminates in Quadrant IV.\n", angle);
    }//switch

    return ;
}//printRes



