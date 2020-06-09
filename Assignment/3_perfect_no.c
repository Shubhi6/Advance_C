/*
   Title-:WAP to check whether the entered number is perfect or not.
   Author-:Shubhi Omar
   Date-:25/9/2019
   Description-: Input-:Read a number from the user.
   Output-:Print whether no is perfect or not.
 */


#include<stdio.h>

int main()

{ 
	//Declare variables
	int num, fact, sum = 0;

	printf("Please enter the number\n");
	scanf("%d" , &num);

	// Checking input is positive or negative
	if (num <= 0)
	{
		printf("can't find perfect or not\n");
	} 
	else
	{
		// Loop for the factors of no
		for (fact = 1; fact < num; fact++)
		{ 

			if (num % fact == 0)
			{
				sum = sum + fact;
			}

		}

		// Condition for checking  given no is perfect no. 
		if (sum == num) 
		{
			printf("%d is a perfect number\n", num);
		}
		else 
		{
			printf("%d is not a perfect number\n", num);
		}
	}
	return 0;
}    



