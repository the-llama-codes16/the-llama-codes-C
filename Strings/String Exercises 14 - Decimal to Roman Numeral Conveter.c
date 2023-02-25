/* A program that works similarly to String Exercises 13 - Roman Numeral to Decimal Converter.
However, the input must be a Decimal Number, and the program will generate its Roman Numeral
equivalent. */

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

#define FLUSH while (getchar() != '\n')

int DeciToRoman(char RomanEquiv[], int* index, int decimal, int pattern, char mainChar, char subChar, int mainNum, int subNum, int secNum);

int main (void) {
    int decimal;
    char RomanEquiv[40] = "";
    int index = 0;
    int actualLen;

    //Getting user input
    printf("\nThis program provides the Roman Numeral form of a number you enter.");
    printf("\nPlease enter a number: ");
    scanf("%d", &decimal);

    //Converting the number to its Roman Numeral form
    if (decimal >= 900) {
        decimal = DeciToRoman(RomanEquiv, &index, decimal, 1, 'M', 'C', 1000, 900, 0);
    }
    if (decimal >= 400) {
        decimal = DeciToRoman(RomanEquiv, &index, decimal, 2, 'D', 'C', 500, 400, 100);
    }
    if (decimal >= 90) {
        decimal = DeciToRoman(RomanEquiv, &index, decimal, 1, 'C', 'X', 100, 90, 0);
    }
    if (decimal >= 40) {
        decimal = DeciToRoman(RomanEquiv, &index, decimal, 2, 'L', 'X', 50, 40, 10);
    }
    if (decimal >= 9) {
        decimal = DeciToRoman(RomanEquiv, &index, decimal, 1, 'X', 'I', 10, 9, 0);
    }
    if (decimal >= 4) {
        decimal = DeciToRoman(RomanEquiv, &index, decimal, 2, 'V', 'I', 5, 4, 1);
    }
    if (decimal <= 3 && decimal >= 1) {
        decimal = DeciToRoman(RomanEquiv, &index, decimal, 3, 'I', ' ', 1, 0, 0);
    }

    actualLen = strlen(RomanEquiv);
    printf("\nThe Roman Numeral form of the number is: ");
    for (int ctr = 0; ctr < actualLen; ctr++) {
        printf("%c", RomanEquiv[ctr]);
    }
    printf("\n");

    return ;

}//main



int DeciToRoman(char RomanEquiv[], int* index, int decimal, int pattern, char mainChar, char subChar, int mainNum, int subNum, int secNum) {
    if (pattern == 1) {
        while (decimal >= mainNum) {
            decimal -= mainNum;
            RomanEquiv[*index] = mainChar;
            (*index)++;
        }
        if (decimal >= subNum) {
            decimal -= subNum;
            RomanEquiv[*index] = subChar;
            (*index)++;
            RomanEquiv[*index] = mainChar;
            (*index)++;
        }
    }//pattern 1

    else if (pattern == 2) {
        while (decimal >= mainNum) {
            decimal -= mainNum;
            RomanEquiv[*index] = mainChar;
            (*index)++;
            while (decimal >= secNum) {
                decimal -= secNum;
                RomanEquiv[*index] = subChar;
                (*index)++;
            }
        }
        if (decimal >= subNum) {
            decimal -= subNum;
            RomanEquiv[*index] = subChar;
            (*index)++;
            RomanEquiv[*index] = mainChar;
            (*index)++;
        }
    }//pattern 2

    else if (pattern == 3) {
        while (decimal >= mainNum) {
            decimal -= mainNum;
            RomanEquiv[*index] = mainChar;
            (*index)++;
        }
    }//pattern 3

    return decimal;
}//DeciToRoman




 /*
 Pattern 1 - MCXI
    char Main
    char Sub
    if number >= 900, Main = M, Sub = C
    if number >= 90, Main = C, Sub = X
    if number >= 9, Main = X, Sub = I
    if number >= 1, Main = I, Sub = ' '

    number = functionToConvert(number, Pattern, MainChar, SubChar, MainNum, SubNum, SecNum)

        while number >= MainNum:
            subtract by MainNum
            RomanEquiv[index] = MainChar
            index++
        if number >= SubNum:
            subtract by SubNum
            RomanEquiv[index] = SubChar
            index++
            RomanEquiv[index] = MainChar
            index++



    Pattern 2 - DLV
    if number >= 400, Main = D, Sub = C
    if number >= 40, Main = L, Sub = X
    if number >= 4, Main = V, Sub = I

    number = functionToConvert(number, Pattern, MainChar, SubChar, MainNum, SubNum, SecNum)

        while number >= MainChar:
            subtract by MainChar
            RomanEquiv[index] = Main
            index++
            while number >= 1:
                subtract by 1
                RomanEquiv[index] = I
                index++
        if number >= 4:
            subtract by 40
            RomanEquiv[index] = I
            index++
            RomanEquiv[index] = V

------------
    2000 - MM
    1000 - M
    900 - CM
    create an array called char RomanEquiv[40]
    index = 0;
    Pattern 1
    while number >= 900(for M):
        while number >= 1000:
            subtract by 1k
            RomanEquiv[index] = M
            index++
        if number >= 900:
            subtract by 900
            RomanEquiv[index] = C
            index++
            RomanEquiv[index] = M
            index++

    800 - DCCC
    700 - DCC
    600 - DC
    500 - D
    400 - CD
    Pattern 2
    while number >= 400(For D):
        while number >= 500:
            subtract by 500
            RomanEquiv[index] = D
            index++
            while number >= 100:
                subtract by 100
                RomanEquiv[index] = C
                index++
        if number >= 400:
            subtract by 400
            RomanEquiv[index] = C
            index++
            RomanEquiv[index] = D


    300 - CCC
    200 - CC
    100 - C
    90 - XC
    Pattern 1
    while number >= 90(for C):
        while number >= 100:
            subtract by 100
            RomanEquiv[index] = C
            index++
        if number >= 90:
            subtract by 900
            RomanEquiv[index] = X
            index++
            RomanEquiv[index] = C
            index++


    80 - LXXX
    70 - LXX
    60 - LX
    50 - L
    40 - XL

    Pattern 2
    while number >= 40(For L):
        while number >= 50:
            subtract by 50
            RomanEquiv[index] = L
            index++
            while number >= 10:
                subtract by 10
                RomanEquiv[index] = X
                index++
        if number >= 40:
            subtract by 400
            RomanEquiv[index] = X
            index++
            RomanEquiv[index] = L




    30 - XXX
    20 - XX
    10 - X
    9  - IX
    Pattern 1
     while number >= 9(for X):
        while number >= 10:
            subtract by 10
            RomanEquiv[index] = X
            index++
        if number >= 9:
            subtract by 90
            RomanEquiv[index] = I
            index++
            RomanEquiv[index] = X
            index++



    8  - VIII
    7  - VII
    6  - VI
    5  - V
    4  - IV
    Pattern 2
     while number >= 4(For V):
        while number >= 5:
            subtract by 5
            RomanEquiv[index] = V
            index++
            while number >= 1:
                subtract by 1
                RomanEquiv[index] = I
                index++
        if number >= 4:
            subtract by 40
            RomanEquiv[index] = I
            index++
            RomanEquiv[index] = V


    3  - III
    2  - II
    1  - I
    Pattern 1
    (for X):
        while number >= 1:
            subtract by 1
            RomanEquiv[index] = I
            index++





    Pattern 1 - MCXI
    char Main
    char Sub
    if number >= 900, Main = M, Sub = C
    if number >= 90, Main = C, Sub = X
    if number >= 9, Main = X, Sub = I
    if number >= 1, Main = I, Sub = ' '

    number = functionToConvert(number, Pattern, MainChar, SubChar, MainNum, SubNum, SecNum)

        while number >= MainNum:
            subtract by MainNum
            RomanEquiv[index] = MainChar
            index++
        if number >= SubNum:
            subtract by SubNum
            RomanEquiv[index] = SubChar
            index++
            RomanEquiv[index] = MainChar
            index++



    Pattern 2 - DLV
    if number >= 400, Main = D, Sub = C
    if number >= 40, Main = L, Sub = X
    if number >= 4, Main = V, Sub = I

    number = functionToConvert(number, Pattern, MainChar, SubChar, MainNum, SubNum, SecNum)

        while number >= MainChar:
            subtract by MainChar
            RomanEquiv[index] = Main
            index++
            while number >= 1:
                subtract by 1
                RomanEquiv[index] = I
                index++
        if number >= 4:
            subtract by 40
            RomanEquiv[index] = I
            index++
            RomanEquiv[index] = V
*/
