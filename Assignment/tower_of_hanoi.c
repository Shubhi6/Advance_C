/*
Title-:WAP for the bitwise operations.
Author-:Shubhi omar
Date-:25/09/2019
Description-:Input-: Read a  no and choice from user and the no of bits to shift
             Output-: 


 */
#include<stdio.h>
//fun declaration
int towerofhanoi(int,char,char,char);

int main()
{       
        //declaration of variable
	int num;
        char option;
     
        do
        {
        //take input from user
	printf("Enter the num of disks:");
	scanf("%d",&num);
        //fu call
	towerofhanoi(num , 'A','B','C');

        printf("\ncontinue(y/n):");
	scanf("\n%c",&option);
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
}

//fun definition
int towerofhanoi(int n, char a,char b,char c)
{       
        //condition for valid no
	if(n <= 0)
	{
		printf("Enter a valid number:\n");
	}
        
        //condition for 1 block
	else if(n == 1)
	{
		printf("\nlower disk %d from %c to %c",n,a,c);
	}

        //condition for more then one
	else
	{       
                //recursive fun  call
		towerofhanoi(n -1,a,c,b);
		printf("\nlower disk %d from %c to %c",n,a,c);
		towerofhanoi(n -1,b,a,c);
	}
        return 0;
}
