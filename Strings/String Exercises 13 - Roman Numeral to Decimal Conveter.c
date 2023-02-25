/* A C program that converts a string representing a number in Roman numeral form
to decimal form.

The symbols used in the Roman Numeral system and their equivalents are:
I   1
V   5
X   10
L   50
C   100
D   500
M   1000

The program must use parallel arrays.

Limitation: Program is not aware of the valid characters and the corresponding rules of Roman Numerals, so
User must enter only the valid characters and stick to the rules.
Side note: I recently became aware of "limitations" due to my work. I can work on addressing this limitation,
but I'll do that in the future when I'm not too lazy with the small details. ~~*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

#define FLUSH while (getchar() != '\n')

void ConvListCreate (char romanNumList[], int deciList[]);
int RomanToDecimal (char romanNumList[], int deciList[], char romanNumInput[], int romanLen, int deciConv[romanLen]);

int main (void) {
    char romanNumList[7];
    int deciList[7];
    char romanNumInput[51] = "";
    int romanLen;
    int deciOutput;

    //Creating the conversion list
    ConvListCreate (romanNumList, deciList);

    //Getting input from user
    printf("\nThis program converts a Roman Numeral entry to a Decimal number.\nExample: XL = 40\n");
    printf("Please refer to this list for the valid characters: \n");
    printf("\tI\t1\n\tV\t5\n\tX\t10\n\tL\t50\n\tC\t100\n\tD\t500\n\tM\t1000\n");
    printf("\nEnter your number in Roman Numeral form: ");
    scanf("%50[^\n]", romanNumInput);
    FLUSH;

    //Creating the array for the decimal conversion
    romanLen = strlen(romanNumInput);
    int deciConv[romanLen];

    //Passing the data to the conversion function
    deciOutput = RomanToDecimal (romanNumList, deciList, romanNumInput, romanLen, deciConv);

    //Printing the generated conversion for checking
    /*for (int ctr = 0; ctr < romanLen; ctr++) {
        printf("%d\n", deciConv[ctr]);
    } */

    //Printing the result
    printf("\nThe equivalent decimal value is: %d\n", deciOutput);

    return 0;
}//main


void ConvListCreate (char romanNumList[], int deciList[]) {
    romanNumList[0] = 'I';
    deciList[0] = 1;
    romanNumList[1] = 'V';
    deciList[1] = 5;
    romanNumList[2] = 'X';
    deciList[2] = 10;
    romanNumList[3] = 'L';
    deciList[3] = 50;
    romanNumList[4] = 'C';
    deciList[4] = 100;
    romanNumList[5] = 'D';
    deciList[5] = 500;
    romanNumList[6] = 'M';
    deciList[6] = 1000;

    return;
}//ConvListCreate

int RomanToDecimal (char romanNumList[], int deciList[], char romanNumInput[], int romanLen, int deciConv[romanLen]) {
    int romanIndexEquiv = 0;

    //getting the decimal equivalent of each character
    for (int index = 0; index < romanLen; index++) {
        for (int ctr = 0; ctr < 7; ctr++) {
            if (romanNumInput[index] == romanNumList[ctr]) {
                romanIndexEquiv = ctr;
                break;
            }
        }
        deciConv[index] = deciList[romanIndexEquiv];
    }


    //combining the values according to their sequence
    bool toSubtract = false;
    int queue = 0;
    int deciOutput = 0;
    int lastIndex = romanLen - 1;

    for (int index = 0; index < romanLen; index++) {
        if (deciConv[index] > deciConv[index + 1] || index == lastIndex) {
            deciOutput += deciConv[index];
            if (toSubtract == true) {
                deciOutput -= queue;
                toSubtract = false;
                queue = 0;
            }
            else if (toSubtract == false) {
                deciOutput += queue;
                queue = 0;
            }
        }

        else if (deciConv[index] < deciConv[index + 1]) {
            queue += deciConv[index];
            toSubtract = true;
        }

        else if (deciConv[index] == deciConv[index + 1]) {
            queue += deciConv[index];
        }

    }

    return deciOutput;
}//RomanToDecimal
