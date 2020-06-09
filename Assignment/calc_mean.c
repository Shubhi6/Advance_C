/*
Title-:WAP for the bitwise operations.
Author-:Shubhi omar
Date-:25/09/2019
Description-:Input-: Read a  no and choice from user and the no of bits to shift
             Output-: 


 */



#include<stdio.h>
#include<stdlib.h>
//fun declartion
void *calc_mean(int n,int ch);

int main()
{       
        //declaratio of variable
	int ch,n;
	void *ptr;
        char option;
        
        do
        {        
        //taking input from user
	printf("1.int\n2.short\n3.float\n4.double\nEnter your choice:");
	scanf("%d",&ch);

	switch(ch)
	{
		case 1: 
			printf("Enter the no of elements:");
			scanf("%d",&n);
                        //fun call
			ptr=calc_mean(n,ch);
                         //free memory
			free(ptr);
			break;

		case 2:
			printf("Enter the no of elements:");
			scanf("%d",&n);
                        //fun call
			ptr=calc_mean(n,ch);
                        //free memory
			free(ptr);
			break;

		case 3:
			printf("Enter the no of elements:");
			scanf("%d",&n);
                        //fun call
			ptr=calc_mean(n,ch);
                        //free memory
			free(ptr);
			break;

		case 4:
			printf("Enter the no of elements:");
			scanf("%d",&n);
                        //fun call
			ptr=calc_mean(n,ch);
                        //free memory
			free(ptr);
			break;

		default:
			printf("Invalid choice");
	}
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
	return 0;
}



//fun definition
void *calc_mean(int n ,int ch)
{       
        //declartion of variable
	int i;
	void *ptr;
	float sum,mean;

	switch(ch)
	{
		case 1: 
                        //for assigning the memory
			ptr= (int *)malloc(sizeof(int) * n);
			printf("Enter the elements");
			for(i =0 ; i <n;i++)
			{
	               	      scanf("%d",(int *)(ptr +i));
			       sum = (int)sum +(*(int *)(ptr + i));
			}
                        //for mean
			mean= (int)sum/(n);
			printf("mean=%d\n",(int)mean);
			break;

		case 2:
                        //for assign the memory
			ptr= (short *)malloc(sizeof(short) * n);
			printf("Enter the elements");
			for(i =0 ; i <n;i++)
			{
				scanf("%hd",(short *)(ptr +i));
			        sum = (short)sum +(*(short *)(ptr + i));
			}
                        //for mean
			mean = (short)sum/(n);
			printf("mean=%hd\n",(short)mean);
			break;
                     

		case 3:
                        //for assign the memory
			ptr= (float *)malloc(sizeof(float) * n);
			printf("Enter the elements");
			for(i =0 ; i <n;i++)
			{
				scanf("%f\n",(float *)(ptr +i));
				sum = (float)sum +(*(float *)(ptr + i));
			}
                        //for mean
			mean = (float)sum/(n);
			printf("mean=%f",(float)mean);
			break;


		case 4:
                        //for assugn the memory
			ptr= (double *)malloc(sizeof(double) * n);
			printf("Enter the elements");
			for(i =0 ; i <n;i++)
			{
				scanf("%lf\n",(double *)(ptr +i));
				 sum = (double)sum +(*(double *)(ptr + i));
			}
                        //for memory
			mean= (double)sum/(n);
			printf("mean=%lf",(double)mean);
			break;

		default:
			printf("Invalid\n");
	}
	return ptr;
}
