/* Write a program to create a customer's bill for a company */

#include<stdio.h>

int main(void)
{
    int tv, vcr, rc, cdp, tr;
    float tottv, totvcr, totrc, totcdp, tottr;
    float subtotal, tax, totalbill;

    const float tvprice = 400.0;
    const float vcrprice = 220.0;
    const float rcprice = 35.2;
    const float cdpprice = 300.0;
    const float trprice = 150.0;

    const float taxrate = 0.0825;

    printf("How many TVs were sold? ");
    scanf("%d", &tv);
    printf("How many VCRs were sold? ");
    scanf("%d", &vcr);
    printf("How many Remote Controllers were sold? ");
    scanf("%d", &rc);
    printf("How many CD Players were sold? ");
    scanf("%d", &cdp);
    printf("How many Tape Recorders were sold? ");
    scanf("%d", &tr);

    //Calculations
    tottv = tv*tvprice;
    totvcr = vcr*vcrprice;
    totrc = rc*rcprice;
    totcdp = cdp*cdpprice;
    tottr = tr*trprice;

    subtotal = tottv+totvcr+totrc+totcdp+tottr;
    tax = subtotal*taxrate;
    totalbill = subtotal+tax;


    printf("\n\n");

    //Headings
    printf("\tQTY\tDESCRIPTION\tUNIT PRICE\tTOTAL PRICE");
    printf("\n\t---\t-----------  \t----------\t-----------\n");

    //Body
    printf("\n\t%-3d\tTV           \t   %6.2f\t%10.2f", tv, tvprice, tottv);
    printf("\n\t%-3d\tVCR          \t   %6.2f\t%10.2f", vcr, vcrprice, totvcr);
    printf("\n\t%-3d\tREMOTE CTRLR \t   %6.2f\t%10.2f", rc, rcprice, totrc);
    printf("\n\t%-3d\tCD PLAYER    \t   %6.2f\t%10.2f", cdp, cdpprice, totcdp);
    printf("\n\t%-3d\tTAPE RECORDER\t   %6.2f\t%10.2f", tr, trprice, tottr);


    printf("\n\t   \t             \t         \t ---------");

    //Subtotal, Tax, Total
    printf("\n\t   \t             \t  SUBTOTAL\t%10.2f",subtotal);
    printf("\n\t   \t             \t  TAX     \t%10.2f",tax);
    printf("\n\t   \t             \t  TOTAL   \t%10.2f",totalbill);

    return 0;
}
