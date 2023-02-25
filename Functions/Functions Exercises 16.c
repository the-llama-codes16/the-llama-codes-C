/* A program that creates customer's bills for a carpet company
given the following information:

a. length and width of carpet in feet
b. carpet price per square foot
c. percent of discount for each customer    */

#include <stdio.h>
#define LABORCOST 0.35
#define TAXRATE 0.085

void reader (int* dimA, int* dimB, int* discount, double* price);
void calc (int dimA, int dimB, int* area, double unitPrice, double* insPrice, double* subtotal, int disrate, double* discountPrice, double* total, double* tax);
double insCalc (int dimA, int dimB, int* areaCopy, double unitPrice);
double subTotalCalc (double insPriceCopy, int disrate, double* discountPriceCopy);
double totalCalc (double subtotalCopy, double* taxCopy);
void printRes (int* dimA, int* dimB, int* area, int* discountrate, double* unitPrice, double* insPrice, double* discountPrice, double* subtotal, double* tax, double* total);


int main (void)
{
    int len, wid, area, dis;
    double unitPrice;
    double insPrice, discountPrice, subtotal, tax, total;


    reader (&len, &wid, &dis, &unitPrice);
    //printf ("**Length: %d\nWidth: %d\nDiscount: %d\nUnit Price: %.2f\n\n", len, wid, dis, unitPrice);

    calc (len, wid, &area, unitPrice, &insPrice, &subtotal, dis, &discountPrice, &total, &tax);
    /*printf ("\n\n**Area: %d\nInstallation Price: %lf\n\n", area, insPrice);
    printf ("\n**Discount Price: %lf\nSubtotal: %lf\n\n", discountPrice, subtotal);
    printf ("\n**Tax: %lf\nTotal: %lf", tax, total); */

    printRes (&len, &wid, &area, &dis, &unitPrice, &insPrice, &discountPrice, &subtotal, &tax, &total);

    return 0;
}

//*****************************reader********************************
void reader (int* dimA, int* dimB, int* discount, double* price)
{
    printf ("Please answer the following.\n");
    printf ("Length of Room (feet): ");
    scanf ("%d", dimA);
    printf("Width of Room (feet): ");
    scanf ("%d", dimB);
    printf ("Customer discount (percent): ");
    scanf ("%d", discount);
    printf ("Cost per square foot (xxx.xx): ");
    scanf ("%lf", price);

    return;
}


//*****************************calc**********************************
void calc (int dimA, int dimB, int* area, double unitPrice, double* insPrice, double* subtotal, int disrate, double* discountPrice, double* total, double* tax)
{
    int areaCopy = 0;
    double insPriceCopy = 0;
    double discountPriceCopy = 0;
    double subtotalCopy = 0;
    double taxCopy = 0;

    *insPrice = insCalc (dimA, dimB, &areaCopy, unitPrice);
    *area = areaCopy;
    insPriceCopy = *insPrice;
    //printf ("**insPriceCopy: %lf", insPriceCopy);

    *subtotal = subTotalCalc (insPriceCopy, disrate, &discountPriceCopy);
    *discountPrice = discountPriceCopy;
    subtotalCopy = *subtotal;
    //printf ("\n**discountPriceCopy: %lf", discountPriceCopy);

    *total = totalCalc (subtotalCopy, &taxCopy);
    *tax = taxCopy;
    //printf ("\nTaxCopy: %lf\nTotal: %lf", taxCopy, *total);

    return;
}

//*****************************insPrice******************************
double insCalc (int dimA, int dimB, int* areaCopy, double unitPrice)
{
    double carpetcost, laborcost;

    *areaCopy = dimA * dimB;
    carpetcost = *areaCopy * unitPrice;
    laborcost = *areaCopy * LABORCOST;

    return (carpetcost + laborcost);
}


//*****************************subTotalCalc**************************
double subTotalCalc (double insPriceCopy, int disrate, double* discountPriceCopy)
{
    double disper;
    disper = disrate / 100.0;
    *discountPriceCopy = disper * insPriceCopy;

    return (insPriceCopy - *discountPriceCopy);
}


//*****************************TotalCalc*****************************
double totalCalc (double subtotalCopy, double* taxCopy)
{
    *taxCopy = subtotalCopy * TAXRATE;

    return (subtotalCopy + *taxCopy);
}

//****************************printRes*******************************
void printRes (int* dimA, int* dimB, int* area, int* discountrate, double* unitPrice, double* insPrice, double* discountPrice, double* subtotal, double* tax, double* total)
{
    printf ("\n\n");
    printf ("                    MEASUREMENT                     ");
    printf ("\n\n");
    printf ("Length                                     %3d feet\n", *dimA);
    printf ("Width                                      %3d feet\n", *dimB);
    printf ("Area                                       %3d sq.ft\n", *area);
    printf ("\n\n\n");
    printf ("                      CHARGES                       ");
    printf ("\n\n");
    printf ("DESCRIPTION         COST/SQ.FT.          CHARGES    \n");
    printf ("-----------         -----------        -------------\n");
    printf ("Carpet                %6.2lf           $%10.2lf     \n", *unitPrice, *unitPrice**area);
    printf ("Labor                 %6.2lf            %10.2lf     \n", LABORCOST, LABORCOST**area);
    printf ("                                       -------------\n");
    printf ("INSTALLED PRICE                        $%10.2lf     \n", *insPrice);
    printf ("Discount                %2d%%             %10.2lf    \n", *discountrate, *discountPrice);
    printf ("                                       -------------\n");
    printf ("SUBTOTAL                               $%10.2lf     \n", *subtotal);
    printf ("Tax                                     %10.2lf     \n", *tax);
    printf ("TOTAL                                   %10.2lf     \n\n", *total);

    return;
}





