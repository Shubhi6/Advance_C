/*
Title-:WAP for the bitwise operations.
Author-:Shubhi omar
Date-:25/09/2019
Description-:Input-: Read a  no and choice from user and the no of bits to shift
             Output-: 


 */




#include<stdio.h>
//fun declaration         
void sort_float_num(int value,float array[]);

int main()
{       
        //decaration of varible
	int count,i,j;
        //take input from user
	printf("Enter the count of float no:");
	scanf("%d",&count);
	float array[count];
        //validatiom
	if (count <= 1)
	{
		printf("Enter the float no more then one");
	}
        //taking the value of array
	for(i = 0; i< count;i++)
	{
		scanf("%f",&array[i]);
	}
	printf("After sorting:\n");
        //function call
	sort_float_num(count,array);
	return 0;
}

//fun deffinition
void sort_float_num(int value,float array[])
{
	//declaration of variable
	int count ,count1,count2 =0;
	float small=array[0],large=array[0],temp;
	//loop to find smallest and larges no
	for(count =0; count<value ;count++)
	{
		if(array[count] < small)
		{
			small = array[count];
		} 
		if (array[count] > large)
		{
			large = array[count];
		}
	}

	printf("sorted array :\n%f",small);
	//for printing sorted array
	while(count2 < (value -1))
	{
		temp =large;
		for (count =0;count <value;count++)
		{
			if (array[count] <= temp && array[count] > small)
			{ 
				temp =array[count];
			}
		}
		printf("%f",temp);
		small=temp;
		count2++;
	}
	printf("\n");
}




