/*
Title-:WAP to generate fibbonacci series less then the given no.
Author-:Shubhi omar
Date-:25/09/2019
Description-:Input-: Read a no.
             Output-:Print fibbonacci series.

*/


#include<stdio.h>

int main()

{       //declare variable
	int i, num, num1 = 0, num2 = 1, num3 = 0;
	printf("Please enter the number to get fibbonacci series\n");
	scanf("%d", &num);



	//loop for giving Fabbonacci upto given no.
	if (num >= 0)
	{ 
		for(i = 0;i <= num + 1;i++)
		{
			if (num3<=num)
			{ 
				printf("%d\n",num3);
			}
			num1 = num2;
			num2 = num3;
			num3 = num2 +num1;
		}
	} 

	else 
	{       //loop for negative FAbbonacci -
		for(i = 0;i >= num - 1;i--)
		{
			num1 = -num3;
			if (num3 >= num && num1 >= num )
			{ 
				printf("%d\n",num3);
			}
			num1 = num2;
			num2 = num3;
			num3 = num1 - num2;
		}
	} 




	return 0;
}    

