/*
   Title-:WAP to generate AP,GP,HP series of  given no.
   Author-:Shubhi omar
   Date-:26/09/2019
   Description-:Input-:first term ,difference and no of terms are given by user.
   Output-AP SERIES-:2 4 6 8 10 
          GP SERIES-:2 4 8 16 32 
         HP SERIES-:0.500000 0.250000 0.166667 0.125000 0.100000:
 */








#include<stdio.h>

int main()
{
	int i,num1,  diff, no_term, ap ,gp;
	float hp; 
	printf("Please enter the starting no");

	scanf("%d",&num1);
	printf("Please enter the difference and no of terms");
	scanf("%d%d",&diff ,&no_term);


	//for the AP series of no-
	ap = num1;
	printf("AP SERIES-:");
	for (i = 0; i < no_term; i++)
	{
		printf("%d ",ap);
		ap = ap + diff;
	} 



	//for the GP series of no-
	gp = num1;
	printf("\nGP SERIES-:");
	for (i=0; i < no_term; i++)
	{
		printf("%d ",gp);
		gp = gp*diff;
	}


	// for HP series of no-
	hp = num1;
	printf("\nHP SERIES-:");
	for(i = 0; i < no_term; i++)
	{       
		hp = 1/hp;
		printf("%f ",hp);
		num1 = (num1 + diff);
		hp=num1;



	}



	return 0;
}


