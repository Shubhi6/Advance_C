/*
Title-:WAP for the bitwise operations.
Author-:Shubhi omar
Date-:25/09/2019
Description-:Input-: Read a  no and choice from user and the no of bits to shift
             Output-: 


 */

#include<stdio.h>
//fun decalration
void float_num(float *num1);
void double_num(double *d_num);

int main()
{      
	//declaration of variable
	int val,mantissa,exponent,sign;
	long int lval,lmantissa;
	int choice;
	char option;
	float num;
	double d_num;

        do
	{       
		//taking the choice from user
		printf("Enter the choice:\n1.float\n2.double\n");
		printf("choice:");
		scanf("%d",&choice);

		//switch case
		switch(choice)
		{
			case 1:
				printf("Enter the float value:");
				scanf("%f",&num);
				printf("sign \t Exponent \t Mantissa\n");
				float_num(&num);
				printf("\n");
				//extracting the float by using address
				break;



			case 2:
				//taking input from user
				printf("Enter the double value:");
				scanf("%lf",&d_num);
				printf("sign \t Exponent:\t Mantissa\n");
				double_num(&d_num);
				//extracting the double value using address
				break;

			default:
				printf("Invalid choice!!");
				break;
		}
		printf("\ncontinue(y/n):");
		scanf("\n%c",&option);
		if(option == 'y')
		{

			continue;
		}
		else
		{ 
			break;
		}

	} while(1);

		return 0;
}



//fun definition
void float_num(float *num1)
{
	int i=0;
        //conversion of float to integer
	int*p=( int *)num1;
	for(i=(sizeof(p)*8/2)- 1;i>=0;i--)
	{       
               //for printing tab
		if(i == 30||i == 22)
		{
			printf("\t");
		}
                //for printing bits
		if(( *p >> i) & 1)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	}
}


//fun definition
void double_num(double *d_num)
{
	int i=0;
        //conversion of double into long int
	long int*p=(long int *)d_num;
	for(i=(sizeof(p)*8)- 1;i>=0;i--)
	{       
                //for printing tab
		if(i == 62||i == 51)
		{
			printf("\t");
		}
                //for printing bits
		if(( *p >> i) & 1)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	}
}






