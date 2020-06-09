/*
   Title-:WAP for the prime no upto given limit.
   Author-:Shubhi omar
   Date-:25/09/2019
   Description-:Input-: Read a limit no from user.
   Output-:Please enter the limit for prime no200
   2  3  5  7  11  19  23  29  31  43  47  53  59  61  67  83  107  131  139  151  173  181  199 
   Do you want to continue(y/n):n


 */


#include<stdio.h>
int main()
{      
       //declaration of variable
	int num,i,j;
        //take input from user
	printf("Please enter the limit of num\n");
	scanf("%d",&num);

        //initialize array
	int array[num + 1];
        //for making in sequence
	for(i =2;i<=num ; i++)
	{
		array[i]=i;
	}
        i=2;
        // loop till square of number
	while(( i * i) <= num)
	{       
		if(array[i] != 0)
		{        
                        //loop till limit of array
			for (j =2 ;j < num ;j++)
			{         
                               //multiple is greater then limit
				if ((array[i] * j) >num)
				{
					break;
				}           
				else
				{     
                                       //assign multiple 0
				       array[(array[i])*j] = 0;
				} 
			}
                }
	        i++;
	} 

                printf("prime range is:");
		for(i=2 ; i<= num ; i++)
		{      // for printing no which is not zero
			if(array[i] !=  0)
			{
				printf("%d\n",array[i]);
			}
		}
		return 0;
	}








