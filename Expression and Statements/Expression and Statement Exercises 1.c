/*A program that follows a given pseudocode
Algorithm Problem26
1 read x
2 read y
3 compute p = x*y
4 compute s = x+y
5 total = s^2 +p * (s-x) * (p+y)
6 print total
End Problem26 */

include<stdio.h>

int main(void)
{
    int x, y, p, s, total;

    printf("Enter value of x: ");
    scanf("%d", &x);

    printf("Enter value of y: ");
    scanf("%d", &y);

    p = x*y;
    s = x+y;
    total = (s*s) + p * (s-x) * (p+y);

    printf("Total: %d", total);

    return 0;
}
