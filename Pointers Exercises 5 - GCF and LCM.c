/* A function that receives 2 integers and returns the
GCF and LCM. */

#include <stdio.h>

void GCFcalc (int* GCF, int fdigit, int sdigit);
void LCMcalc (int* LCM, int GCF, int fdigit, int sdigit);
void printRes (int GCF, int LCM, int fdigit, int sdigit);

 int main (void) {
     int fdigit;
     int sdigit;
     int GCF;
     int LCM;

     printf ("\nThis program determines the GCF and LCM of two numbers.\n");
     printf ("\nGCF = Greatest Common Factor");
     printf ("\nLCM = Least Common Multiple");

     printf ("\n\nPlease enter two numbers: ");
     scanf ("%d%d", &fdigit, &sdigit);

     GCFcalc (&GCF, fdigit, sdigit);
     LCMcalc (&LCM, GCF, fdigit, sdigit);

     printRes (GCF, LCM, fdigit, sdigit);

     return 0;
 }//main


 void GCFcalc (int* GCF, int fdigit, int sdigit) {
     int big;
     int small;
     int temp;

     if (fdigit > sdigit) {
        big = fdigit;
        small = sdigit; }
     else {
        big = sdigit;
        small = fdigit; }

     while (big % small != 0) {
        big = big - small;

        if (small > big) {
            temp = small;
            small = big;
            big = temp;
        }
     }

     *GCF = small;

     return ;
 }//GCFcalc


 void LCMcalc (int* LCM, int GCF, int fdigit, int sdigit) {
     *LCM = (fdigit * sdigit) / GCF;

     return ;
 }//LCMcalc


 void printRes (int GCF, int LCM, int fdigit, int sdigit) {
     printf ("\n%d and %d", fdigit, sdigit);
     printf ("\nGCF: %d", GCF);
     printf ("\nLCM: %d\n\n", LCM);

     return ;
 }//printRes

