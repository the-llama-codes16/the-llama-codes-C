/* This program adds the 3 least significant digits of a number
entered by user (ones, tens, hundreds) */

#include<stdio.h>

int addThreeDig(int num);
int firstDig (int num);
int secDig (int num);
int thirDig (int num);

int main (void)
{
    int inputnum, sum = 0;

    printf ("Enter a number: ");
    scanf ("%d", &inputnum);

    sum = addThreeDig (inputnum);
    printf ("\nThe sum of the 3 least significant digits of %d is %d.\n\n", inputnum,sum);

    return 0;
}

//*************addThreeDig**************
int addThreeDig (int num)
{
    int result;

    result = firstDig(num) + secDig(num) + thirDig(num);

    return result;
}


//*************firstDig*****************
int firstDig (int num)
{
    return (num % 10);
}

//*************secDig*******************
int secDig (int num)
{
    return (num % 100 / 10);
}

//*************thirDig******************
int thirDig (int num)
{
    return (num % 1000 / 100);
}
