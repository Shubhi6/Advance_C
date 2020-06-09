/*
Title-:WAP for the factorial of function using only main function.
Author-:Shubhi omar
Date-:25/09/2019
Description-:Input-: Read a  no from user.
             Output-: ./factoral_main.out 
                     Enter num: 4
                     Factorial:24


 */







#include<stdio.h>

int main()
{
	//declaring variable
	static int return_value, num, temp=1, flag=1;

	//for taking no.
	if (flag == 1)
	{
		printf("Enter num:");
		scanf("%d",&num);

		flag=0;
	}
	//for input validation
	if (num < 0)
	{
		printf("ERROR!");
		return 1;
	}

	else if (num == 0)
	{
		printf("Factorial=1\n");
		return 1;
	}

	else
	{     
		//for factorial of number
		(temp = temp * num--);

	}

	//for num greater then one
	if(num < 1)
	{
		printf("Factorial:%d\n",temp);
		return 0;

	}
	else 
	{
		main();
	}
}
