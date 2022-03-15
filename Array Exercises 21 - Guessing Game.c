/* A program that simulates a guessing game.

Process:
1. The program generates a random number in the range 1 - 36.
2. The program asks the user his desired number of points.
3. The program asks how many guesses the user wants to make, up to 5.
4. The program displays the following keywords for each guess:
    O   Odd      - The number is odd (get 1 x points risked if correct)
    E   Even     - The number is even (get 1 x points risked if correct)
    L   Low      - The number is low (1 - 12) (get 2 x points risked if correct)
    M   Med      - The number is medium (13 - 24) (get 2 x points risked if correct)
    H   High     - The number is high (25 - 36) (get 2 x points risked if correct)
    F   Left     - The number is on the left of the guess board (get 2 x points risked if correct)
    C   Center   - The number is on the center of the guess board (get 2 x points risked if correct)
    R   Right    - The number is on the right of the guess board (get 2 x points risked if correct)
    N   Number   - Guess the number itself (get 3 x points risked if correct)

                    GUESS BOARD

            LEFT        CENTER          RIGHT
            01            02             03
    LOW     04            05             06
            07            08             09
            10            11             12
    --------------------------------------------
            13            14             15
            16            17             18
    MEDIUM  19            20             21
            22            23             24
    --------------------------------------------
            25            26             27
            28            29             30
    HIGH    31            32             33
            34            35             36
    --------------------------------------------


5. The program asks for the keyword guess and the corresponding points to be risked.
6. After all guesses have been made, the program displays the random number generated
and displays the result of the player's guesses as well as points risked.

Note: The program must use at least 4 arrays with 5 elements each.
1. type of guess
2. number (if guess is Num)
3. points risked
4. points earned or lost
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMenu (void);
int guessGame (int number, int guesses, int points, char guessType [*], int guessNum [*], int riskPoint [*], int guessPoint [*]);
char prinRes (int number, int guesses, int points, int pointsLeft, char guessType [*], int guessNum [*], int riskPoint [*], int guessPoint [*]);

int main (void) {
    int number;
    int points;
    int pointsLeft;
    int guesses;
    char again;
    int loops = 0;

    srand (time (NULL));

    do {
        number = rand () % 36 + 1;

        if (loops == 0) {
            printf ("\nPlease enter points desired: ");
            scanf ("%d", &points); }
        else {
            points = pointsLeft; }

        printMenu ();

        printf ("\nPlease enter desired guesses (up to 5): ");
        scanf ("%d", &guesses);
        if (guesses > 5) {
            guesses = 5; }

        char guessType [guesses];
        int guessNum [guesses];
        int riskPoint [guesses];
        int guessPoint [guesses];
        pointsLeft = guessGame (number, guesses, points, guessType, guessNum, riskPoint, guessPoint);
        again = prinRes (number, guesses, points, pointsLeft, guessType, guessNum, riskPoint, guessPoint);
        loops++;

    } while (again == 'Y');

    return 0;
}//main


void printMenu (void) {
    printf ("\n\n\nGUESSES CHOICES\n");
    printf ("\nO        Odd");
    printf ("\nE        Even");
    printf ("\nL        Low");
    printf ("\nM        Med");
    printf ("\nH        High");
    printf ("\nF        Left");
    printf ("\nC        Center");
    printf ("\nR        Right");
    printf ("\nN        Number\n\n");

    return ;
}//printMenu


int guessGame (int number, int guesses, int points, char guessType [guesses], int guessNum [guesses], int riskPoint [guesses], int guessPoint [guesses]) {
    int pointsLeft = points;

    for (int ctr = 0; ctr < guesses; ctr++) {
        printf ("\nGuess %d", ctr + 1);
        printf ("\nEnter your choice: ");
        scanf (" %c", &guessType [ctr]);
        guessType [ctr] = toupper (guessType [ctr]);

        if (guessType [ctr] == 'N') {
            printf ("Enter your number: ");
            scanf ("%d", &guessNum [ctr]);
        }

        printf ("Points at risk: ");
        scanf ("%d", &riskPoint [ctr]);
        if (riskPoint [ctr] > pointsLeft) {
            printf ("\nYou do not have enough points to continue.\n");
            exit (0);
        }

        switch (guessType [ctr]) {
            case 'O':
                if (number % 2 != 0) {
                    guessPoint [ctr] = riskPoint [ctr];
                    pointsLeft += guessPoint [ctr]; }
                else {
                    guessPoint [ctr] = - (riskPoint [ctr]);
                    pointsLeft += guessPoint [ctr]; }
                break;
            case 'E':
                if (number % 2 == 0) {
                    guessPoint [ctr] = riskPoint [ctr];
                    pointsLeft += guessPoint [ctr]; }
                else {
                    guessPoint [ctr] = - (riskPoint [ctr]);
                    pointsLeft += guessPoint [ctr]; }
                break;
            case 'L':
                if (number <= 12) {
                    guessPoint [ctr] = 2 * riskPoint [ctr];
                    pointsLeft += guessPoint [ctr]; }
                else {
                    guessPoint [ctr] = -riskPoint [ctr];
                    pointsLeft += guessPoint [ctr]; }
                break;
            case 'M':
                if (number >= 13 && number <= 24) {
                    guessPoint [ctr] = 2 * riskPoint [ctr];
                    pointsLeft += guessPoint [ctr]; }
                else {
                    guessPoint [ctr] = -riskPoint [ctr];
                    pointsLeft += guessPoint [ctr]; }
                break;
            case 'H':
                if (number >= 25 && number <= 36) {
                    guessPoint [ctr] = 2 * riskPoint [ctr];
                    pointsLeft += guessPoint [ctr]; }
                else {
                    guessPoint [ctr] = -riskPoint [ctr];
                    pointsLeft += guessPoint [ctr]; }
                break;
            case 'F':
                if (number % 3 == 1) {
                    guessPoint [ctr] = 2 * riskPoint [ctr];
                    pointsLeft += guessPoint [ctr]; }
                else {
                    guessPoint [ctr] = -riskPoint [ctr];
                    pointsLeft += guessPoint [ctr]; }
                break;
            case 'C':
                if (number % 3 == 2) {
                    guessPoint [ctr] = 2 * riskPoint [ctr];
                    pointsLeft += guessPoint [ctr]; }
                else {
                    guessPoint [ctr] = -riskPoint [ctr];
                    pointsLeft += guessPoint [ctr]; }
                break;
            case 'R':
                if (number % 3 == 0) {
                    guessPoint [ctr] = 2 * riskPoint [ctr];
                    pointsLeft += guessPoint [ctr]; }
                else {
                    guessPoint [ctr] = -riskPoint [ctr];
                    pointsLeft += guessPoint [ctr]; }
                break;
            case 'N':
                if (guessNum [ctr] == number) {
                    guessPoint [ctr] = 3 * riskPoint [ctr];
                    pointsLeft += guessPoint [ctr]; }
                else {
                    guessPoint [ctr] = -riskPoint [ctr];
                    pointsLeft += guessPoint [ctr]; }
                break;
            default:
                printf ("\nInvalid input.\n");
                exit (0);
        }
    }

    return pointsLeft;
}//guessGame


char prinRes (int number, int guesses, int points, int pointsLeft, char guessType [guesses], int guessNum [guesses], int riskPoint [guesses], int guessPoint [guesses]) {
    int pointSum = 0;
    char again;

    printf ("\n-------------------RESULTS-----------------------");
    printf ("\nMy number is: %d\n", number);
    printf ("\nPrevious Points: %d", points);
    printf ("\nGuess     Type     Number     Risked     Won/Loss\n");

    for (int ctr = 0; ctr < guesses; ctr++) {
        if (guessType [ctr] == 'N') {
            printf ("  %d        %c         %2d        %4d        %+4d\n", ctr + 1, guessType [ctr], guessNum [ctr], riskPoint [ctr], guessPoint [ctr]);
        }
        else {
            printf ("  %d        %c                   %4d        %+4d\n", ctr + 1, guessType [ctr], riskPoint [ctr], guessPoint [ctr]);

        }

        pointSum += guessPoint [ctr];
    }

    printf ("\nYou won %d points this turn.", pointSum);
    printf ("\nYour new balance is: %d", pointsLeft);
    printf ("\nDo you want to play again (Y or N) ? ");
    scanf (" %c", &again);
    again = toupper (again);

    return again;
}//prinRes



