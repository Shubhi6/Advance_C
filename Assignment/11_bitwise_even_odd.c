/*
   Title-:WAP to check whether the entered number is positive ,negative or even or odd.
   Author-:Shubhi Omar
   Date-:25/9/2019
   Description-: Input-:Read a number from the user.
   Output-: No is positive or negative ,even or odd.
 */



#include<stdio.h>

int main()
{      //Declare variables
	int num;
	printf("Please enter the no");
	scanf("%d",&num);

        //condition for odd no.
	if(num & 1)
	{       
                //condition for negative.
		if (num & (1 << 31))
		{
			printf("%d is a negative  odd no\n",num);
		}
		else 
		{
			printf("%d is positive odd no \n",num);
		}
	}
	else
	{       //
		if (num & (1 << 31))
		{
			printf("%d is a negative even no\n",num);
		}
		else 
		{
			printf("%d is positive even no\n ",num);
		}
	}
	return 0;
}
