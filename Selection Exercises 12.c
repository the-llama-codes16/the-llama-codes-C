/* Write a function called parkingCharge that,
given the type of vehicle (c for car, b for bus, t for truck)
and the hours a vehicle spent in the parking lot,
returns the parking charge based on the rates shown below:

car $2 per hour
bus $3 per hour
truck $4 per hour */

#include <stdio.h>

float parkingCharge (char* type, float* hours);

int main (void)
{
    char type;
    float hours;
    float charge;

    printf ("Please enter number of parking hours: ");
    scanf ("%f", &hours);
    printf ("\nType of vehicle:\nPlease enter\nc for car\nb for bus\nt for truck: ");
    scanf (" %c", &type);

    type = tolower (type);

    if (type == 'c' || type == 'b' || type == 't')
    {
        charge = parkingCharge (&type, &hours);
        printf ("\nParking Charge: $%.2f\n", charge);
    }
    else
        printf ("\nInvalid vehicle type.\n");

    return 0;
}//main

float parkingCharge (char* type, float* hours)
{
    float payperhour;

    switch (*type)
    {
        case 'c':
            payperhour = 2;
            break;
        case 'b':
            payperhour = 3;
            break;
        case 't':
            payperhour = 4;
            break;
    }//switch type

    return (payperhour * *hours);
}//parkingCharge
