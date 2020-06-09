/*
Title-:WAP for the bitwise circular left shift and circular right shift.
Author-:Shubhi omar
Date-:25/09/2019
Description-:Input-: Read a  no and choice from user and the no of bits to shift
             Output-: 


 */



#include<stdio.h>

//function declaration
int circular_left_shift(int num, int n);
int circular_right_shift(int num, int n);
void print_bits(unsigned int num);

int main()
{       
       // for declaring variable
	int num, n, result;
	int choice;
	char option;

	do{     
               //for taking information from user
		printf("Enter num:");
		scanf("%d", &num);
                printf("Please enter the bits to shift:");
                scanf("%d", &n);
		printf("Enter choice\n 1.circular_right_shift \n 2.circular_left_shift\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1: 
                                //for taking value
				printf("Circular_right_shift \n");
				printf("%d ",num);
                                //function call
				print_bits(num);
				result=circular_right_shift(num, n);
				printf("new number");
                                //function call for print result in bits
				print_bits(result);
				break;

			case 2:
                                //for taking value
				printf("Circular_left_shift \n");
				printf("%d",num);
                                //function call
				print_bits(num);
				result=circular_left_shift(num, n);
				printf("new number ");
                                //function call for printing bits in result
				print_bits(result);
				break;



			default:
				printf("INVALID CHOICE");
				break;
		}

		printf("continue(y/n):");
		scanf("\n%c",&option);
		if (option == 'y')
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

//for right shift
int circular_right_shift(int num,int n)
{
	return ((num >> n) |(num << (32 - n)));
}

//for left shift
int circular_left_shift(int num,int n)
{
	return ((num << n) | ((num >> (32- n)))); 
}

//for printing in bit format
void print_bits(unsigned int num)
{
	int i, bit, mask;
	for(i = 31;i >= 0;i--)
	{
		mask = 1 << i;
		bit = mask & num;
		bit == 0 ? printf("0"):printf("1");
	}
	printf("\n");
}
