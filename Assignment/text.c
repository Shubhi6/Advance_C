/*
Title-:WAP for the prime no upto given limit.
Author-:Shubhi omar
Date-:25/09/2019
Description-:Input-: Read a limit no from user.
             Output-:Print prime number.

*/


#include<stdio.h>
int main()
{
	int num,i,j;
        char option;
//do
//{
	printf("Please enter the limit for prime no");
       	scanf("%d",&num);
        
        int array[num +1];
        array[0]=0;
        array[1]=0;

	for(i=2;i<=num;i++)
        {
        array[i]=i;
        }		
               for(i = 2; i <=num; i++)  

		{   
                         
                  for (j=2;j<=num;j++)
                      {

			
                      	
		            array[(i * j)]=0;
                                break; 
			}

	
	      } 
        
         for(i=2;i<=num;i++) 
	{
	if (array[i] != 0)
	{
		printf("%d \n",array[i]);
	}
        }
        
      
	return 0;
}















