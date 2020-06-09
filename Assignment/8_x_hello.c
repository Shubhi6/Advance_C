/*
Title-:WAP to generate hello in x format.
Author-:Shubhi omar
Date-:25/09/2019
Description-:Input-: Read a no by user.
             Output-:Print  hello.
                     Enter the number of lines:4
                      HELLO  HELLO
                       HELLOHELLO 
                       HELLOHELLO 
                      HELLO  HELLO

Enter the number of lines:5
HELLO    HELLO
 HELLO  HELLO 
  HELLOHELLO  
 HELLO  HELLO 
HELLO    HELLO

*/

#include<stdio.h>

int main()
{ 
	// declare variable
	int num , row, coloumn;

	//Read input from user
	printf("Enter the number of lines:");
	scanf("%d",&num);

	if(num > 2)
	{
		//check coloumn and row conditions
		for(row = 0;row < num; row++)
		{ 
			for(coloumn = 0;coloumn < num ;coloumn++)
			{ 
				if((row == coloumn) || coloumn == (num -row) -1)
				{
					printf("HELLO");
				}
				else 
				{
					printf(" ");
					if(num % 2 == 1 && coloumn == num/2)
						printf(" ");
				}

				//print middle one
				if(row == coloumn && coloumn == (num - row)-1)
				{	
                                  printf("HELLO");
                                }
			}
			printf("\n");
		}
	}
	return 0;
}
