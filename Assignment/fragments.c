/*
Title:- WAP to find the average of the framents using FSSD 
Author:- Shubhi omar
Date:- 10/10/19
Description:- Input: Enter the number of rows:
                     2
                     Enter the number of columns for row[0]: 3
                     Enter the number of columns for row[1]: 4
                     Enter the elements for row[0]:
                     1 2 
                     Enter the elements for row[1]:
                     2 3 4

                     Array before sorting
                     1.0 2.0 1.5 
                     2.0 3.0 4.0 3.0 

                     Sorted array according to average
                     1.0 2.0 
                     2.0 3.0 4.0 
                    	      
*/



#include<stdio.h>
#include<stdlib.h>

//Function declaration
void average(int row, int *col, float **ptr);

int main()
{
    //Declaring local variables
    int row, count, count1;

    printf("Enter the number of rows:\n");
    scanf("%d", &row);

    int col[row+1];

    float *ptr[row];

    //Loop to enter columns according rows and memory allocation for colums
    for (count = 0; count < row; count++)
    {
	printf("Enter the number of columns for row[%d]: ", count);
	scanf("%d", &col[count]);
	ptr[count] = (float *)malloc(sizeof(float) * col[count]);
    }

    //Loop to enter elements rows and columns
    for (count = 0; count < row; count++)
    {
	printf("Enter the elements for row[%d]:\n", count);
	for (count1 = 0; count1 < (col[count] - 1); count1++)
	{
	    scanf("%f", (*(ptr + count) + count1));
	}
    }
    printf("\nArray before sorting\n");
    //Call function sort elements based on average
    average(row,col,ptr);

    printf("\nSorted array according to average\n");
    for (count = 0; count < row; count++)
    {
	for (count1 = 0; count1 < (col[count] - 1); count1++)
	{
	    printf("%0.1f ", (*(*(ptr + count) + count1)));
	}
	printf("\n");
    }

    //Loop to free memory 
    for (count1 = 0; count1 < row; count1++)
    {
	free(ptr[count1]);
    }
    return 0;
}

//Function to sort elements based on average
void average(int row, int *col, float **ptr)
{
    float temp[10];
    int temp1, count, count1, count2, count3, const_col = 0;
    float sum = 0;

    //Loop to sum rows and columns elements
    for (count = 0; count < row; count++)
    {
	for (count1 = 0; count1 < (col[count] - 1); count1++)
	{
	    //Calculte sum
	    sum = sum + *(*(ptr + count) + count1);
	}
	//Calculte average
	sum = (sum / (col[count] - 1));
	(*(*(ptr + count) + count1)) = sum;
	sum = 0;
    }
    //Loop to print average values in last new column
    for (count = 0; count < row; count++)
    {
	for (count1 = 0; count1 < (col[count]); count1++)
	{
	    printf("%0.1f ", (*(*(ptr + count) + count1)));
	}
	printf("\n");
    }

    for (count = 0; count < row; count++)
    {
	for (count2 = (count+1); count2 < row; count2++)
	{
	    for (count1 = (col[count2] - 1);1;)
	    {
		const_col = col[count] - count;
		if ((*(*(ptr+count) + (col[count] - 1))) >= (*(*(ptr+count2)+count1)))
		{
		    for (count3 = 0; count3 < (col[count]); count3++)
		    {
			temp[count3] = (*(*(ptr + count) + count3));
		    }
		    ptr[count] = (float *)realloc(ptr[count],sizeof(float)*col[count3]);
		    for (count3 = 0; count3 < (col[count2]); count3++)
		    {
			(*(*(ptr+count)+count3)) = (*(*(ptr+count2)+count3));
		    }
		    ptr[count2] = (float *)realloc(ptr[count2],sizeof(float)*col[count]);
		    for (count3 = 0; count3 < (col[count]); count3++)
		    {
			(*(*(ptr+count2)+count3)) = temp[count3];
		    }
		    temp1 = col[count];
		    col[count] = col[count2];
		    col[count2] = temp1;
		}
		else
		    break;
	    }
	}
    }
}
