
/*
Title-:WAP for the bitwise operations.
Author-:Shubhi omar
Date-:25/09/2019
Description-:Input-: Read a  no and choice from user and the no of bits to shift
             Output-: 


 */


#include<stdio.h>

//function declaration
void print_bits( unsigned int);
int replace_nbits_from_pos(int,int,int,int);

int main()
{
        //variable declaration
	int num,val,a,b;
	int result;
	char choice,option;
	do
	{       
                //input from user
		printf("Enter the num:");
		scanf("%d",&num);
		print_bits(num);
		printf("\nEnter the value:\n");
		scanf("%d",&val);

		printf("\nEnter the a:\n");
		scanf("%d",&a);
                
                //limit of a
		if(a < 0 || a >31)
		{
			return 0;
		}


		printf("\nEnter the b:\n");
		scanf("%d",&b);

                //limit of b
		if(b < 0 || b >31)
		{
			return 0;
		}

		int c = b - a + 1;
                
                //function call
		result= replace_nbits_from_pos(val,num,a,c);
		printf("result=%d\n" ,result);
                
                //fun for printing bits
		print_bits(result);


		printf("Do you want to continue(y/n):");
		scanf("\n%c", &option);
		{
			if(option == 'y')
			{
				continue;
			}
			else
			{
				break;
			}

		}


	}while(1);
	return 0;
}



//function definition
int replace_nbits_from_pos(int val,int num,int a,int c)
{
	return(val & ~(~(~0 << c)<<a)) | ( num & ~(~0 << a)) <<c;
}
//function definition
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

