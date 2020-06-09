/*
Title-:WAP for the bitwise operations.
Author-:Shubhi omar
Date-:25/09/2019
Description-:Input-: Read a  no and choice from user and the no of bits to shift
             Output-: 


 */

#include<stdio.h>
#include<stdlib.h>
//fun declaration
void magic_square(int num);

int main()
{       
        //declaration of variable
	int num;
        //taking input from user
	printf("Enter the num:");
	scanf("%d",&num);
        //for odd no
	if (num % 2 == 0)
	{
		printf("PLease enter odd no\n");
	}
	else
	{        
                //fun calling
		magic_square( num);
		return 0;

	}
	//	return 0;
}


//fun definition
void magic_square(int num)
{
        //declaration of variable
	int i,j;
	int *arr[num];
        //loop for allocating memory
	for (i =0;i<num;i++)
	{
		arr[i]= (int *)calloc(num,sizeof(int));
	}
	i = 0;
	j = num/2;
        //loop for allocating value
	for(int n =1;n <= num* num;++n)
	{
		arr[i][j]=n;
                //condition
		if(n % num == 0)
		{
			i++;
		}
		else
		{
			i--;
			j++;
		}
		if(i < 0)
		{
			i= num - 1;
		}
		if(j == num)
		{
			j = 0;
		}
	}
	
        printf("magic square for %d is:\n",num);
        //loop for printing element
	for (i = 0;i<num;i++)
	{
		for(j = 0;j<num;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");

	}
}
