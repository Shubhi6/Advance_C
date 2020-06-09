/*
Title-:WAP for the bitwise operations.
Author-:Shubhi omar
Date-:25/09/2019
Description-:Input-: Read a  no and choice from user and the no of bits to shift
             Output-: 


 */

#include<stdio.h>
#include "14_bits_library.h"
//function declaration
/*int get_nbits(int num,int n);
int get_nbits_from_pos(int num,int n, int pos);
int toggle_nbits_from_pos(int num ,int n, int pos);
void print_nbits(unsigned int num);
void print_bits(unsigned int num);*/

/*int main()
{       
        //declaration of variable
	int num, n, result, val, pos;
	int choice;
	char option;

	do{     
       
		printf("Please select the bit operation:\n1.get_n_bits\n2.replace_n_bits\n3.get_nbits_from_position\n4.replace_nbits_from_pos\n5.toggle_n_bits");
		//for taking information from user
		printf("\nEnter choice");
		scanf("%d", &choice);

		printf("Enter num:");
		scanf("%d", &num);
		printf("Please enter the bits:");
		scanf("%d", &n);

		if(choice == 2 || choice == 4)
		{ 
			printf("Enter val:");
			scanf("%d" ,&val);
		}  
		if(choice == 3 || choice == 4 || choice  == 5)
		{ 
			printf("Enter pos:");
			scanf("%d" ,&pos);
		}        
                
                //switch case for  taking choice              
		switch(choice)
		{
			case 1: 
				//for taking value
                                print_bits(num);
				printf("%d ",get_nbits(num,n));
				printf("\n");
				//function call for print result in bits
				print_bits(result);
				break;

			case 2:
                                print_bits(num);
				printf("%d ",replace_nbits(num,n ,val));
				printf("\n");
				//function call for print result in bits
				print_bits(result);
				break;

			case 3:
                                print_bits(num);
				printf("%d ",get_nbits_from_pos(num,n ,pos));
				printf("\n");
				//function call for print result in bits
				print_bits(result);
				break;

			case 4:
                                print_bits(num);
				printf("%d ",replace_nbits_from_pos(num,n ,val,pos));
				printf("\n");
				//function call for print result in bits
				print_bits(result);
				break;


			case 5:
                                print_bits(num);
				printf("%d ",toggle_nbits_from_pos(num,n ,pos));

				printf("\n");
				//function call for print result in bits
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
}*/



//function definition
int get_nbits(int num ,int n)
{        
        //variable declaration
	int result ,mask,i;
        //masking of no to get result
	mask = (( 1 << n) - 1);
	result = num & mask;
	return result;
}


//function definition
int replace_nbits(int num ,int n,int val)
{       
        //variable declaration
	int result ,mask;
        //masking of no
	mask = (( 1 << n) - 1);
	result = (num & ~ mask) |val;
	return result;
}

//function definition
int get_nbits_from_pos(int num ,int n,int pos)
{       
        //variable declartion
	int result ,mask;
        //masking of no
	mask = (( 1 << n) - 1);
	result= (num >> pos -1) & mask;
	return result;
}


//function definition
int replace_nbits_from_pos(int num ,int n ,int pos ,int val)
{
        //declarion of variable
	int result ,mask;
        //masking of no
	mask = (( 1 << n) - 1) << ((pos -n ) + 1);
	result = num & ~mask;
	val= (( val & ((1 << n) -1)) << ((pos -n) + 1));
	result = result |val;
	return result;
}


//function definiton
int toggle_nbits_from_pos(int num ,int n, int pos)
{      
        //declartion of variable
	int result ,mask;
        //making of no
	mask = (( 1 << n) - 1) << ((pos -n) + 1);
	result= num ^ mask;
	return result;
}

//function definition for printing bits
void print_bits(unsigned int num)
{
	int i, bit, mask;
        //loop for printing bits
	for(i = 31;i >= 0;i--)
	{
		mask = 1 << i;
		bit = mask & num;
		bit == 0 ? printf("0"):printf("1");
	}
	printf("\n");

}
