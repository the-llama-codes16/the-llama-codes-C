/* A program that has a for loop that will produce
the following sequences:

a. 6, 8, 10, 12, ..., 66
b. 7, 9, 11, 13, ..., 67
c. The sum of the numbers between 1 and 15 inclusive
d. The sum of the odd numbers between 15 and 45 inclusive
e. The first 50 numbers in the series 1, 4, 7, 10, ...

*/

int main (void)
{
    //a. 6, 8, 10, 12, ..., 66
    printf ("\n");

    for (int i = 6; i <= 66; i+=2)
        printf ("%d ", i);


    //b. 7, 9, 11, 13, ..., 67
    printf ("\n\n");

    for (int i = 7; i <= 67; i+=2)
        printf ("%d ", i);


    //c. The sum of the numbers between 1 and 15 inclusive
    printf ("\n\n");

    int sum = 0;

    for (int i = 1; i <= 15; i++)
        sum += i;

    printf ("Sum = %d", sum);


    //d. The sum of the odd numbers between 15 and 45 inclusive
    printf ("\n\n");

    sum = 0;

    for (int i = 15; i <= 45; i+=2)
        sum += i;

    printf ("Sum = %d", sum);


    //e. The first 50 numbers in the series 1, 4, 7, 10, ...
    printf ("\n\n");

    int num = 1;

    for (int i = 1; i <= 50; i++)
    {
        printf ("%d ", num);
        num += 3;
    }

    printf ("\n");

    return 0;
}
