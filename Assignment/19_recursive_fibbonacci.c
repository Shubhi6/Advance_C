/*
Title-:WAP for the bitwise operations.
Author-:Shubhi omar
Date-:25/09/2019
Description-:Input-: Read a  no and choice from user and the no of bits to shift
             Output-: 


 */

#include<stdio.h>
//fun declaration
int fibb1(int num1,int num2,int limit);
int fibb2(int num1,int num2,int limit);

int main()
{    

        //declaration of variable
	int limit, i ,sum =0,num1=0,num2=1;
	char ch;
	do
	{

                //take information from user
		printf("Please enter the limit of fibbonacci series:");
		scanf("%d",&limit);

                 //for positive fibbonacci series
		if(limit >=0)
		{
			fibb1(num1,num2,limit); 
		}
		else
		{       
                  //for negative fibbonacci series
			fibb2(num1,num2,limit);
		}
		printf("Do you want to continue: ");
		scanf("\n%c",&ch);

		 if (ch == 'y')
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

//function definition
int fibb1(int num1,int num2,int limit)
{
	int sum=0;
	if (num1 <= limit )
	{
		printf("%d\n",num1);
		sum= num1 +num2;
		num1 =num2;
		num2=sum;
		fibb1(  num1, num2,limit); 
	}


}
        //function definition
int fibb2(int num1,int num2,int limit)
	{
		int sum=0;
		if(num1 <= -limit && num1>=limit )
		{
			printf("%d\n",num1);
			sum= num1 -num2;
			num1 =num2;
			num2=sum;
			fibb2(  num1, num2,limit); 
		
                }
        }
