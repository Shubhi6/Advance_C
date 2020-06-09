/*
Title-:WAP for the swapping of number using function.
Author-:Shubhi omar
Date-:25/09/2019
Description-:Input-: Read a  no from user.
             Output-:Please enter two numbers for swapping: 3 4
                     After swapping: num1=4 ,num2=3
*/









#include<stdio.h>
//function declaration
void swap(int*a,int*b);

int main()
{
	//declaring variable
	int num1, num2;

	printf("Please enter two numbers for swapping:");
	scanf("%d %d",&num1, &num2);

	//function calling
	swap(&num1,&num2);
	printf("After swapping: num1=%d ,num2=%d\n",num1,num2);
	return 0;
}

//function definition
void swap(int *a,int *b)
{
	*a=*a^*b;//toggling for swapping
	*b=*b^*a;
	*a=*a^*b;

}
