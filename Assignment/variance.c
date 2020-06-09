/*
Title:- WAP to variance calculation with static and dyanamic. 
Author:- Shubhi Omar
Date:- 10/10/19
Description:- Input: Enter the array size:
                     10
		     arr[0] = 9
                     arr[1] = 12
                     arr[2] = 15
                     arr[3] = 18
                     arr[4] = 20
                     arr[5] = 22
                     arr[6] = 23
                     arr[7] = 24
                     arr[8] = 26
                     arr[9] = 31
             Output: Mean = 20

d^2   Diff(D) = Num-Mean   NUM
---   -----------------    ------
 121	 	-11 	   9
 64	 	-8 	   12
 25	 	-5 	   15
 4	 	-2 	   18
 0	 	 0 	   20
 4	 	 2 	   22
 9	 	 3 	   23
 16	 	 4 	   24
 36	 	 6 	   26
 121	 	11 	   31
--------------------------------
sum : 200		 sum(D^2) : 400

The Variance : 40

*/
#include<stdio.h>
#include<stdlib.h>

//Function declarations
void variance (int *, int, int *, int, int *);

int main()
{

    //Declaring local variables
    int num, mean, sum = 0, dsum = 0, count;
    int choice;
    int *arr;

    //Read input from user
    printf("Enter the number of elements:\n");
    scanf("%d", &num);

    int array[num];

    printf("1.static array \n2.Dynamic array:\n");
    printf("Enter your choice:\n");
    scanf("%d", &choice);

    //Switch case
    switch (choice)
    {
	case 1:
	    //Loop to static array
	    for (count = 0; count < num; count++)
	    {
		printf("[%d] : ", count);
		scanf("%d", &array[count]);
		sum = sum + array[count];
	    }
	    //Loop to print array of elements
	    for (count = 0; count < num; count++)
	    {
		printf("arr[%d] = %d\n",count, array[count]);
	    }
	    //Calculate mean
	    mean = sum / num;
	    printf("Mean = %d\n", mean);
	    //Call function to calculate variance of array
	    variance(array, num, &sum, mean, &dsum);
	    break;
	case 2:
	    //Allocate memory for array dyamically
	    arr = (int *)malloc(num * sizeof(int));
	    for (count = 0; count < num; count++)
	    {
		printf("[%d] : ", count);
		scanf("%d", &arr[count]);
		sum = sum + arr[count];
	    } 
	    for (count = 0; count < num; count++)
	    {
		printf("arr[%d] = %d\n",count, arr[count]);
	    }
	    //calculate mean
	    mean = sum / num;
            printf("Mean = %d\n", mean);
	    //Call function to calculate variance of array
	    variance(arr, num, &sum, mean, &dsum);
	    break;
    }
}

//Function to find variance and d^2 sum
void variance(int *array, int num, int* sum, int mean, int* dsum)
{
    printf("\nd^2   Diff(D) = Num-Mean   NUM\n");
    printf("---   -----------------    ------\n");
    //Loop to find difference and d^2 sum
    for (int count = 0; count < num; ++count) 
    {		
	printf(" %d\t \t%2d \t   %d\n", *(array+count) *= *(array+count) , *(array+count) -= mean, *(array+count));
	*dsum = *dsum + *(array+count);
    }
    printf("--------------------------------\n");
    printf("sum(D^2) : %d\t\t sum : %d\n\nThe Variance : %d\n", *dsum, *sum, *dsum/num); 
}

