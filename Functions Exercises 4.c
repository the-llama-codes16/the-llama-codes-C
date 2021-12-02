/* Sample of top-down development using stubs */

#include<stdio.h>

int initialize (void);
int process (void);
int endOfJob (void);

int main(void)
{
    printf("Begin program \n\n");

    initialize();
    process();
    endOfJob();

    return 0;
}


//****************INITIALIZE********************
int initialize(void)
{
    printf("In initialize\n");
    return 0;
}


//*****************PROCESS**********************
int process(void)
{
    printf("In process: \n");
    return 0;
}

//****************endOfJob**********************
int endOfJob(void)
{
    printf("In endOfJob: \n");
    return 0;
}
