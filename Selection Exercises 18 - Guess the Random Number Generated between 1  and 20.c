/* A simple guessing game program that generates a random
number between 1 and 20. The user is given up to 5 tries
to guess the exact number. After each guess, the user must
be told if the guessed number is greater than, less than,
or equal to the random number. Five guesses are allowed until
the user gets the number right. If he does not, he must be
told what the number is.

Between = excluding the endpoints
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getGuess (void);
void guessCheck (int guess, int ranNum);
void unsuccessful (ranNum);
void successful (ranNum);


int main (void)
{
    int ranNum, guess;

    srand (time(NULL));
    ranNum = rand () % 18 + 2;
    //printf("***random number generated: %d\n", ranNum);

    guess = getGuess ();
    //printf ("***data from getGuess: %d\n", guess);

    guessCheck (guess, ranNum);

    return 0;
}//main


int getGuess (void)
{
    int guess;

    printf ("\n\tI am thinking of a number between 1 and 20.\n");
    printf ("\tCan you guess what it is? ");
    scanf ("%d", &guess);

    if (guess > 19 || guess < 2)
    {
        printf ("\tPlease enter a number between 1 and 20.\n");
        exit (1);
    }

    return guess;
}//getGuess


void guessCheck (int guess, int ranNum)
{
    int counter = 1;
    while (counter < 5)
    {
        if (guess == ranNum)
        {
            break;
        }

        else if (guess > ranNum)
        {
            printf ("\tYour guess is too high. Try again: ");
            scanf ("%d", &guess);
            counter++;
        }
        else if (guess < ranNum)
        {
            printf ("\tYour guess is too low. Try again: ");
            scanf ("%d", &guess);
            counter++;
        }

        if (guess > 19 || guess < 2)
        {
            printf ("\tPlease enter a number between 1 and 20.\n");
            exit (1);
        }
    }

    if (guess != ranNum)
    {
        unsuccessful (ranNum);
    }
    else
    {
        successful (ranNum);
    }

    return ;
}//guessCheck


void unsuccessful (ranNum)
{
    printf ("\n\tSorry. The number was %d.\n", ranNum);
    printf ("\tYou should have gotten it by now.\n\tBetter luck next time.\n");
}

void successful (ranNum)
{
    printf ("\n\tCongratulations! The number is %d. You guessed it!\n", ranNum);
}

