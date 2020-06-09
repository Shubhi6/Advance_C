/*
Title-:WAP for the median of array.
Author-:Shubhi omar
Date-:25/09/2019
Description-:Input-: Read a  no from user.
             Output-:Please enter the  limit of positive number: 3
2
2
3
Median of entered number in array_1 is 2.000000 
Please enter the  limit of positive number: 4
2
3
2
2
Median of entered number in array_2 is 2.000000 
median is :2.000000   DO YOU WANT TO CONTINUE(y/n):n


*/



#include<stdio.h>

int main()

{       
	//declaring variable
	int num1, num2, i, j, i1, j1, temp,temp1;
	float average, median1, median2 ;
	char option;

	do
	{

		printf("Please enter the  limit of positive number:");
		scanf("%d\n",&num1);

		int array1[num1];

		// checking condition for negative no.
		if (num1 <= 0)
		{
			printf("ERROR:INVALID NUMBER");
			continue;
		}
		else
		{        
			//loop for the taking no in array 
			for (i=1; i <= num1; i++)
			{

				scanf("%d",&array1[i]);
			}

			//loop for sorting
			for( i=0; i < num1; i++)
			{
				for (j=i; j < num1; j++)
				{
					if (array1[j] < array1[i])
					{
						temp = array1[i];
						array1[i] = array1[j];
						array1[j] = temp;
					}
				}
			}
		}
	     
			//median for odd no
			if ((num1 % 2) != 0)
			{
				median1= array1[(num1+1)/2];
			}

			//median for even no
			else
			{
				median1= (array1[num1/2] + array1[(num1/2) + 1]) / 2.00;
			}
	                

		


		printf("Please enter the  limit of positive number:");
		scanf("%d\n",&num2);

		int array2[num2];
		// checking condition for negative no.
		if (num2 <= 0)
		{
			printf("ERROR:INVALID NUMBER");
			continue;
		}
		else
		{        
			//loop for the taking no in array 
			for (i1 = 1; i1 <= num2; i1++)
			{

				scanf("%d",&array2[i1]);
			}

			//loop for sorting
			for (i1 = 0; i1 < num2; i1++)
			{
				for (j1 = i1; j1 < num2; j1++)
				{
					if (array2[j1] < array2[i1])
					{
						temp1 = array2[i1];
						array2[i1] = array2[j1];
						array2[j1] = temp1;
					}
				}
			}
		}
		       
			//median for odd no
			if ((num2 % 2) != 0)
			{
				median2= array2[(num2+1)/2];
			}
                        
                        //median for even no
			else
			{
				median2= ((array2[num2/2] + array2[(num2/2 )+1]) / 2.00);
			}
		        
                        
                   		
                average = ((median1 + median2) / 2.00);
                printf("median is :%f",average);

		printf("DO YOU WANT TO CONTINUE(y/n):");
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
