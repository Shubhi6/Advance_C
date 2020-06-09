/*
Title-:WAP to print integer.
Author-:Shubhi omar
Date-:25/09/2019
Description-:Input-: Read a no.
             Output-:Print int no.

*/



#include<string.h>
#include<stdio.h>
//fun declaration
void read_int(int*);

int main()
{
	//declaration of variable
	char option;
        int num;
	do
	{       
		//taking no in buffer
		char s[255]={0};
		//take input from user
		printf("Enter the value:");
		//function call
		read_int(&num);
		printf("Number=%d\n",num);
		printf("\ncontinue(y/n):");
		scanf("%c",&option);
		if(option == 'y')
		{
			getchar();
			continue;
		}
		else
		{ 
			break;
		}

	} while(1);
	return 0;
}


//function definition
void read_int(int *num)
{
	char ch;
	int flag = 0;
	*num =0;
	//taking character
	while((ch= getchar()) != '\n')	
	{ 
		//condition for both negative ,positive sign and number
		if (ch == 45 || ch == 43 || (ch >=48 && ch <=57))
		{ 
			//for positive sign
			if (ch == 45)
			{
				flag = 1;
				continue;
			}
			//for negative sign
			else if (ch == 43)
			{
				continue;
			}
			//for number without positive sign
			else
			{
				*num = (10 * (*num)) + (ch - 48);
			}
		}
	}
	//for printing negative number
	if (flag == 1)
	{
		*num = -1 * (*num);
	}
	
}
