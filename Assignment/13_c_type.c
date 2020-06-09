/*
Title-:WAP for the c_library.
Author-:Shubhi omar
Date-:25/09/2019
Description-:Input-: Read a  character to check and the choice  from user.
             Output-: 


 */
#include<stdio.h>
//function declaration
int isalpha(int var);
int isalnum(int var);
int isascii(int var);
int isblank(int var);
int isdigit(int var);
int iscntrl(int var);

int main()

{        
        //declaring variables
	int choice;
	char var;

	printf("Please enter  the value to check:");
	scanf("%c",&var);
	printf("1.isalpha\n2.isalnum\n3.isascii\n4.isblank\n5.isdigit\n6.iscntrl\n");
	printf("Please enter the choice:");
	scanf("%d",&choice);
	{       
                //switch case for choices
		switch(choice)
		{
			case 1:
                                //function calling using ternery operator
				isalpha(var)?printf("1\n"):printf("0\n");
				break;
			case 2:
				isalnum(var)?printf("1\n"):printf("0\n");
				break;
			case 3:
				isascii(var)?printf("1\n"):printf("0\n");
				break;
			case 4:
				isblank(var)?printf("1\n"):printf("0\n");
				break;
			case 5:
				isdigit(var)?printf("1\n"):printf("0\n");
				break;
			case 6:
				iscntrl(var)?printf("1\n"):printf("0\n");
				break;
			default:
				printf("INVALID CHOICE");
		}
	}
	return 0;
}

//function definition
int isalpha(int var)
{
	if((var >= 97 && var <= 122) || (var >= 65 && var <=90))
	{
		return 1;
	}
	return 0;

}


int isalnum(int var)
{
	if((var >= 'A' && var <= 'Z') || (var >= 'a' && var <= 'z') || (var>='0' && var<= '9'))
	{
		return 1;
	}
	return 0;

}

int isascii(int var)
{
	if((var >= 0 && var <= 127))
	{
		return 1;
	}
	return 0;

}


int isdigit(int var)
{
	if(var >= '0' &&  var <= '9')
	{
		return 1;
	}
	return 0;

}


int iscntrl(int var)
{
	if(var >= 0 && var <= 31 || (var == 127))
	{
		return 1;
	}
	return 0;

}

int isblank (int var)
{
	if (var == 9 || var == 32)
	{
		return 1;
	}
	return 0;

}
