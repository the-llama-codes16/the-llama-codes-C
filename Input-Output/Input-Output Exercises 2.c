#include<stdio.h>
int main(void)
{
    int quantity;
    float unitPrice;
    printf("Enter quantity and unit price separated by one space:\n");
    scanf("%d %f", &quantity, &unitPrice);
    printf("\n\nQuantity: %d\tUnit Price: %.2f", quantity, unitPrice);
    return 0;
}
