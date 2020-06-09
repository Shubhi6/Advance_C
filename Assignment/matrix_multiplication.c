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
void matrix_multi(int **ptr1, int **ptr2,int **ptr_res,int row,int col,int col1);
void print(int row,int col,int **ptr);
void my_free(int row,int col,int **ptr);

int main()
{       
        //declaration of variable
	int row,col,row1,col1,row2,col2,i,j,count = 0,sum = 0;
	char option;
        
        do
        {
        //take input from user
	printf("Enter the row and coloumn of matrix:\n");
	scanf("%d %d",&row1,&col1);
        
       //assign the value for multiplication
	row2 = col1;
	col2 = row1;
	row = row1;
	col = col1;
        
        //allocation of memory for row1 and col1
	int **ptr1 = (int **) malloc( row1 * sizeof(int));
	for(i =0; i < row1;i++)
	{
		ptr1[i]=(int*) malloc(col1 *sizeof(int));
	}
        
        //allocation of memory for row2 and col2
	int **ptr2 = (int **) malloc( row2 * sizeof(int));
	for(i =0; i < row2;i++)
	{
		ptr2[i]=(int*) malloc(col2 *sizeof(int));
	}
        
        //allocation of memory for resultant
	int **ptr_res = (int **) malloc( row * sizeof(int));
	for(i =0; i < row;i++)
	{
		ptr_res[i]=(int*) malloc(col *sizeof(int));
	}
      
        //for taking elements from user
	printf("Enter the elements of matrix\n");
	for(i = 0;i <row1 ;i++)
	{
		for(j =0 ;j <col1;j++)
		{
			scanf("%d",&ptr1[i][j]);
		}
	}
        
        //for transpose of matrix
	for(i = 0;i< row1; i++)
	{
		for(j =0; j<col1;j++)
		{
			ptr2[j][i]=ptr1[i][j];
		}
	}

         //for print matrix
	printf("Input Matrix\n");
	print(row1,col1,ptr1);

	printf("Transpose Matrix\n");
	print(row2,col2,ptr2);

	matrix_multi(ptr1,ptr2,ptr_res,row,col,col1);
	printf("result of matrix multiplication\n");
	print(row,col,ptr_res);

          //for free the memory
	my_free(row1,col1,ptr1);
	my_free(row2,col2,ptr2);
	my_free(row,col,ptr_res);
//        my_free(row2,col2,ptr2);
  //       my_free(row1,col1,ptr1);

	printf("Do you want to continue(y/n):");
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

	
}while(1);
return 0;
}

//fun definition
void matrix_multi(int **ptr1, int **ptr2,int **ptr_res,int row,int col,int col1)
{
        //declaratio of variable
	int i,j,k=0,sum=0;
        //matrix multiplication
	for(i = 0;i <row; i++)
	{
		for(j =0 ;j<col;j++)
		{
			for(k=0;k<col1;k++)
			{
				ptr_res[i][j] += ptr1[i][k] *ptr2[k][j];
			}
		}

	}

}

//fun definition
void print(int row,int col,int **ptr)
{
	int i,j;
         //for printing matrix
	for(i = 0;i <row ;i++)
	{
		for(j =0;j <col;j++)
		{
			printf("%d ",(*(*(ptr + i) + j)));
		}
		printf("\n");
	}
	printf("\n");
}

//fun definition for free of memory
void my_free(int row,int col,int **ptr)
{
	int i;
	for(i =0 ;i< row;i++)
	{
		free(ptr[i]);
	}
	free(ptr);
}
