#include <stdio.h>

int main(void)
{
	/*This program will print a report.
	Print column headers */
	printf("\tPart Number\tQty on Hand");
	printf("\tQty on Order\tPrice\n");
	//Print details
	printf("\t%06d\t\t%d\t\t%d\t\t$%7.2f\n", 31235, 22, 86, 45.62);
	printf("\t%06d\t\t%d\t\t%d\t\t$%7.2f\n", 321, 55, 21, 122.0);
	printf("\t%06d\t\t%d\t\t%d\t\t$%7.2f\n", 28764, 0, 24, 0.75);
	printf("\t%06d\t\t%d\t\t%d\t\t$%7.2f\n", 3232, 12, 0, 10.91);
	printf("End of Report");
	return 0;
	//code is complete

}



