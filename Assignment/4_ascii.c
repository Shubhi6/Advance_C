/*
   Title-:WAP to print ASCII table.
   Author-:Shubhi Omar
   Date-:25/9/2019
   Description-: Input-:no input
   Output-:Print ASCII table
 */


#include<stdio.h>

int main()

{ 
	//Declare variables
	int num; 

	printf("Octal\tDecimal\tHexadec\tASCII\n ");
	printf("----\t-------\t-------\t-------\n");

	// loop for all the ASCII values 
	for (num = 0; num <= 127; num++)
	{       
		// loop for non-printable characters
		if (num < 32) 
		{
			printf("%o\t  %d\t  %x\t  non-printable characters\n",  num,num,num);
		}

		else if (num == 127) 
		{
			printf("%o\t  %d\t  %x\t  non-printable characters\n",  num,num,num);
		}

		//loop for printable characters
		else if (num > 32) 
		{
			printf("%o\t  %d\t  %x\t  %c\n" ,num, num,num,num);
		}
	}

	return 0;
}    



