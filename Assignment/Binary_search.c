/*Author:Shubhi omar
Date:10/12/2019
Description : A program for binary search for any data types
Input : Size of array through command line
Output : Seacrched element with its position
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//function for binary search
void bin_srch(void *arr, int argv2, void *srch, int type)	
{
    int i, j;
    if(type == 1)										
    {
	int array[argv2];
	for(i = 0; i < argv2; i++)
	    //typecasting passed argument to integer
	    array[i] = *((int *)arr + i);	
	//setting first element
	int start = 0;	
	//setting last element
	int end =argv2-1;							
	int middle;	
	//runs until start and end are next to each other

	while( start <= end )						
	{
	    middle = (start + end) / 2;
	    //searching for search element within array
	    if( *(int *)srch == array[middle] )	
	    {
		//printing message if element is found
		printf("Search element %d is at position %d of array\n", *(int *)srch, middle);
		break;
	    }
	    //condition if entered element is greater than middle element

	    else if(*(int *)srch > array[middle])
		start = middle + 1;
	    else
		end = middle - 1;		
	}
	//if element is not found                      
	if(start > end)							
	    printf("Search element %d not found\n", *(int *)srch);
    }
    //for character type
    if(type == 2)										
    {
	char array[argv2];
	for(i = 0; i < argv2; i++)
	    //typecasting passed argument to character
	    array[i] = *((char *)arr + i);		
	int start = 0;
	int end = argv2 - 1;
	int middle;
	while( start <= end )
	{
	    middle = (start + end) / 2;
	    if( *(char *)srch == array[middle] )
	    {
		printf("Search element %c is at position %d of array\n", *(char *)srch, middle);
		break;
	    }							
	    else if ( *(char *)srch > array[middle] )
		start = middle + 1;
	    else
		end = middle - 1;		
	}
	if(start>end)
	    printf("Search element %c not found\n", *(char *)srch);
    }
    //for float type
    if(type == 3)									
    {
	float array[argv2];
	for(i = 0; i < argv2; i++)
	    //typecasting passed argument to float
	    array[i] = *((float *)arr + i);
	int start = 0;
	int end = argv2 - 1;
	int middle;
	while( start <= end )
	{
	    middle = (start + end) / 2;
	    if( *(float *)srch == array[middle] )
	    {
		printf("Search element %f is at position %d of array\n", *(float *)srch, middle);
		break;
	    }							
	    else if ( *(float *)srch > array[middle] )
		start = middle + 1;
	    else
		end = middle - 1;		
	}
	if(start>end)
	    printf("Search element %f not found\n", *(float *)srch);
    }
    //for double type
    if(type == 4)
    {
	double array[argv2];
	for(i = 0; i < argv2; i++)
	    //typecasting passed argument to double
	    array[i] = *((double *)arr + i);
	int start = 0;
	int end = argv2 - 1;
	int middle;
    	while( start <= end )
    	{
    	    middle = (start + end) / 2;
    	    if( *(double *)srch == array[middle] )
    	    {
    	    	printf("Search element %lf is at position %d of array\n", *(double *)srch, middle);
    	    	break;
    	    }							
    	    else if ( *(double *)srch > array[middle] )
    	    	start = middle + 1;
    	    else
    	    	end = middle - 1;		
    	}
    	if(start > end)
    	    printf("Search element %lf not found\n", *(double *)srch);
    }
}

int main(int argc, char *argv[])
{
    if(argc == 1)	//if no CLA are passed
    {
    	printf("Enter number of elements through command line\n");
    	exit(0);
    }
    int argv1 = atoi(argv[1]);	//converting entered characters to integers
    int i, j, choice, intv[argv1], int_temp, d_srch;

    char charv[argv1], char_temp, c_srch;
    float floatv[argv1], float_temp, f_srch;
    double doublev[argv1], double_temp, lf_srch;

    printf("Enter your choice:\n1)int\n2)char\n3)float\n4)double\n");
    printf("Choice : ");
    scanf("%d", &choice);
    printf("Enter the elements\n");

    switch(choice)
    {
    	case 1:	//for int type
    	    for(i = 0; i < argv1; i++)	//scanning input
    	    {
    	    	printf("%d. ", i + 1);
    	    	scanf("%d", &intv[i]);
    	    }
    	    for(i = 0; i < argv1 - 1; i++)	//technique for bubble sorting
    	    {
    	    	for(j = 0; j < argv1 - i - 1; j++)		
    	    	{
    	    	    if(intv[j] > intv[j+1])
    	    	    {
    	    	    	int_temp = intv[j];	
    	    	    	intv[j] = intv[j+1];
    	    	    	intv[j+1] = int_temp;
    	    	    }
								}
	    }
	    printf("After sorting : ");
	    for(i = 0; i < argv1; i++)	//printing sorted elements
	    	printf("%d ", intv[i]);
	    printf("\nEnter the key element to search : ");
	    scanf("%d", &d_srch);
	    bin_srch(intv, argv1, &d_srch, 1);	//calling function for binary search
	    break;
	case 2:	//for char type
	    {
	    	for(i = 0; i < argv1; i++)
	    	{
	    	    getchar();
	 	    printf("%d. ", i + 1);
	 	    scanf("%c", &charv[i]);
	 	}
	 	for(i = 0; i < argv1 - 1; i++)	
	 	{
	 	    for(j = 0; j < argv1 - i - 1; j++)		
	 	    {
	 	    	if(charv[j] > charv[j+1])
	 	    	{
	 	    	    char_temp = charv[j];	
	 	    	    charv[j] = charv[j+1];
	 	    	    charv[j+1] = char_temp;
	 	    	}
	 	    }
	 	}
	 	printf("After sorting : ");
	 	for(i = 0; i < argv1; i++)
	 	    printf("%c ", charv[i]);
	 	getchar();
	 	printf("\nEnter the key element to search : ");
	 	scanf("%c", &c_srch);
	 	bin_srch(charv, argv1, &c_srch, 2);
	    }
	    break;
	case 3:	//for float
	    {
	    	int j;
	    	for(i = 0; i < argv1; i++)
	    	{
	    	    printf("%d. ", i + 1);
	    	    scanf("%f", &floatv[i]);	
	    	}
	    	for(i = 0; i < argv1 - 1; i++)	
	    	{
	    	    for(j = 0; j < argv1 - i - 1; j++)		
	    	    {
	    	    	if(floatv[j] > floatv[j+1])
	    	    	{
	    	    	    float_temp = floatv[j];	
	    	    	    floatv[j] = floatv[j+1];
	    	    	    floatv[j+1] = float_temp;
	    	    	}
	    	    }
	    	}
	    	printf("After sorting : ");
	    	for(i = 0; i < argv1; i++)
	    	    printf("%f ", floatv[i]);
	    	printf("\nEnter the key element to search : ");
	    	scanf("%f", &f_srch);
	    	bin_srch(floatv, argv1, &f_srch, 3);
	    }
	    break;
	case 4:	//for double
	    for(i = 0; i < argv1; i++)
	    {
	    	printf("%d. ", i + 1);
	    	scanf("%lf", &doublev[i]);
	    }
	    for(i = 0; i < argv1 - 1; i++)	
	    {
	    	for(j = 0; j < argv1 - i - 1; j++)		
	    	{
	    	    if(doublev[j] > doublev[j+1])
	    	    {
	    	    	double_temp = doublev[j];	
	    	    	doublev[j] = doublev[j+1];
	    	    	doublev[j+1] = double_temp;
	    	    }
	    	}
	    }
	    printf("After sorting : ");
	    for(i = 0; i < argv1; i++)
	    	printf("%lf ", doublev[i]);
	    printf("\nEnter the key element to search : ");
	    scanf("%lf", &lf_srch);
	    bin_srch(doublev, argv1, &lf_srch, 4);
	    break;
    }
}
