/*
   Title-:WAP for the prime no upto given limit.
   Author-:Shubhi omar
   Date-:25/09/2019
   Description-:Input-: Read a limit no from user.
   Output-:

 */

#include<stdio.h>
//function declaration
int pre_inc(int *num);
int post_inc(int *num);

int main()
{
        //declaration of variable
	int num, choice, val;
	char option;

	do
	{       
                //take input from user
		printf("Enter the choice:\n1.post_increment\n2.pre_increment\n");
		scanf("%d",&choice);
		printf("Please enter the number;");
		scanf("%d",&num);
                
                //switch case for choice
		switch(choice)
		{
			case 1:
                                //function call
				val = pre_inc(&num);
				printf("val = %d ,num = %d", val, num);
				break;
			case 2:
                                //function call for post increment
				val = post_inc(&num);
				printf("val = %d,num = %d",val,num);
				break;
			default:
				printf("INVALID CHOICE");

		}
		printf("continue:(y/n)");
		scanf("%c",option);
		if(option =='y')    
		{
			continue;
		}
		else
		{
			break;
		}
	}while(1);   
	return 0;
}





//function defiition for post increment
int post_inc (int *num)
{
	unsigned int mask = 1;
	while(*num & mask)
	{
		*num =*num & (~mask);
		mask = (mask << 1);
	}
	*num=*num |mask;
	return *num;
}

//function definition for pre increment
int pre_inc(int *num)
{
	int i=*num;
	unsigned int mask=1;
	while(*num & mask)
	{
		*num =*num & (~mask);
		mask=(mask << 1);
	}
	*num =*num |mask;
	return i;
}
