/* A program that calculates the parking fare for customers
who park their cars in a parking lot given the following info:

a. character representing vehicle type:
    C for car
    B for bus
    T for truck
b. integer between 0 to 24 showing the hour the vehicle entered
the lot.
c. integer between 0 to 60 showing the minute.
d. integer between 0 to 24 showing hour of exit.
e. integer between 0 to 60 showing minute of exit.

Rates:
Car:
    $0 / hr for the first 3 hrs
    $1.50 / hr after 3 hrs
Truck:
    $1 / hr for the first 2 hrs
    $2.30 / hr after 2 hrs
Bus:
    $2 / hr for the first hr
    $3.70 / hr after 1st hr


Note: Must round total time spent to the next hour.
      No overnight parking. Vehicle will be towed.
Note: I added error messages for graceful exit, something
      I learned from studying Python. */




#include <stdio.h>
#define CARMIN 3
#define CARBASE 0.0
#define CARMORE 1.5
#define TRUCKMIN 2
#define TRUCKBASE 1.0
#define TRUCKMORE 2.30
#define BUSMIN 1
#define BUSBASE 2.0
#define BUSMORE 3.70

void getData (char* vtype, int* enhr, int* enmin, int* exhr, int* exmin);
void calcHours (char vtype, int enhr, int enmin, int exhr, int exmin, int* thour, int* tmin, int* hourRounded);
float calcCharge (char vtype, int hourRounded);
float chargeCar (int hour);
float chargeBus (int hour);
float chargeTruck (int hour);
void printRes (char vtype, int enhr, int enmin, int exhr, int exmin, int thour, int tmin, int hourRounded, float charge);



int main (void)
{
    char vtype;
    int enhr, enmin, exhr, exmin;
    int thour, tmin, hourRounded;
    float charge;

    getData (&vtype, &enhr, &enmin, &exhr, &exmin);
    //printf ("\n***Data from getData: %c %d %d %d %d\n", vtype, enhr, enmin, exhr, exmin);

    calcHours (vtype, enhr, enmin, exhr, exmin, &thour, &tmin, &hourRounded);
    //printf ("\n***Data from calcHours: %d %d %d\n", thour, tmin, hourRounded);

    charge = calcCharge (vtype, hourRounded);
    //printf ("\n***Data from calcCharge: %.3f", charge);

    printRes (vtype, enhr, enmin, exhr, exmin, thour, tmin, hourRounded, charge);

    return 0;
}//main


void getData (char* vtype, int* enhr, int* enmin, int* exhr, int* exmin)
{
    //for vehicle type
    printf ("\n\tThis program calculates the parking charge.\n\tPlease provide the following.");
    printf ("\n\t\tType of Vehicle (C for car, B for Bus, T for truck) ? ");
    scanf (" %c", vtype);
    *vtype = toupper (*vtype);
    if (!(*vtype == 'C' || *vtype == 'B' || *vtype == 'T'))
    {
        printf ("\n\tInvalid input. Please enter C, B, or T.\n");
        exit (1);
    }

    //for hour of entry
    printf ("\t\tHour vehicle entered lot (0 - 24)? ");
    scanf ("%d", enhr);
    if (*enhr > 24 || *enhr < 0)
    {
        printf ("\n\tInvalid input. Please enter a number from 0 to 24.\n");
        exit (1);
    }

    //for minute of entry
    printf ("\t\tMinute vehicle entered lot (0 - 60)? ");
    scanf ("%d", enmin);
    if (*enmin < 0 || *enmin > 60)
    {
        printf ("\n\tInvalid input. Please enter a number from 0 to 60.\n");
        exit (1);
    }

    //for hour of exit
    printf ("\t\tHour vehicle left lot (0 - 24)? ");
    scanf ("%d", exhr);
    if (*exhr > 24 || *exhr < 0)
    {
        printf ("\n\tInvalid input. Please enter a number from 0 to 24.\n");
        exit (1);
    }

    if (*exhr < *enhr)
    {
        printf ("\n\tInvalid input. Please check entry and exit hours.\n");
        printf ("\n\tWe do not allow overnight parking. Vehicle will be towed.\n");
        exit (1);
    }



    //for minute of exit
    printf ("\t\tMinute vehicle left lot (0 - 60)? ");
    scanf ("%d", exmin);
    if (*exmin < 0 || *exmin > 60)
    {
        printf ("\n\tInvalid input. Please enter a number from 0 to 60.\n");
        exit (1);
    }

    if (*exhr == *enhr && *exmin < *enmin)
    {
        printf ("\n\tInvalid input. Please check entry and exit minutes.\n");
        exit (1);
    }

    return ;
}//getData


void calcHours (char vtype, int enhr, int enmin, int exhr, int exmin, int* thour, int* tmin, int* hourRounded)
{
    if (exmin < enmin)
    {
        exmin = exmin + 60;
        exhr = exhr - 1;
    }

    *thour = exhr - enhr;
    *tmin = exmin - enmin;

    if (*tmin > 0)
        *hourRounded = *thour + 1;
    else
        *hourRounded = *thour;

    return ;
}//calcHours


float calcCharge (char vtype, int hourRounded)
{
    float charge;

    switch (vtype)
    {
        case 'C':
            charge = chargeCar (hourRounded);
            break;
        case 'B':
            charge = chargeBus (hourRounded);
            break;
        case 'T':
            charge = chargeTruck (hourRounded);
    }

    return charge;
}//calcCharge


float chargeCar (int hour)
{
    float charge, chargePartial;
    int excesshr;

    if (hour > CARMIN)
    {
        excesshr = hour - CARMIN;
        chargePartial = excesshr * CARMORE;
        charge = chargePartial + (CARMIN * CARBASE);
    }
    else
        charge = hour * CARBASE;

    return charge;
}//chargeCar


float chargeBus (int hour)
{
    float charge, chargePartial;
    int excesshr;

    if (hour > BUSMIN)
    {
        excesshr = hour - BUSMIN;
        chargePartial = excesshr * BUSMORE;
        charge = chargePartial + (BUSMIN * BUSBASE);
    }
    else
        charge = hour * BUSBASE;

    return charge;
}//chargeBus


float chargeTruck (int hour)
{
    float charge, chargePartial;
    int excesshr;

    if (hour > TRUCKMIN)
    {
        excesshr = hour - TRUCKMIN;
        chargePartial = excesshr * TRUCKMORE;
        charge = chargePartial + (TRUCKMIN * TRUCKBASE);
    }
    else
        charge = hour * TRUCKBASE;

    return charge;
}//chargeTruck


void printRes (char vtype, int enhr, int enmin, int exhr, int exmin, int thour, int tmin, int hourRounded, float charge)
{
    printf ("\n\n");
    printf ("\t        PARKING LOT CHARGE             \n\n");

    switch (vtype)
    {
        case 'C':
            printf ("\tType of Vehicle:               Car\n");
            break;
        case 'B':
            printf ("\tType of Vehicle:               Bus\n");
            break;
        case 'T':
            printf ("\tType of Vehicle:             Truck\n");
    }

    printf ("\t        TIME IN:             %02d:%02d\n", enhr, enmin);
    printf ("\t       TIME OUT:             %02d:%02d\n", exhr, exmin);
    printf ("\t                          --------\n");
    printf ("\t   PARKING TIME:             %02d:%02d\n", thour, tmin);
    printf ("\t   ROUNDED TIME:             %02d:00\n", hourRounded);
    printf ("\t                          --------\n");
    printf ("\t   TOTAL CHARGE:            $%5.2f\n", charge);

    return ;
}




