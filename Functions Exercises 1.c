/* A program that includes a  user-defined function that will print
name and a main function that calls such function */

#include<stdio.h>

void NameBox(void);

int main(void)
{
    NameBox();

    return 0;
}


//******************NameBox**********************
void NameBox(void)
{
    printf("\t******************************");
    printf("\n\n");
    printf("\t*                            *");
    printf("\n\n");
    printf("\t*  Iam  Rasendi  M.  Saldua  *");
    printf("\n\n");
    printf("\t*                            *");
    printf("\n\n");
    printf("\t******************************\n\n");
    return;
}
