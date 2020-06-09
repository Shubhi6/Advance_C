/*
Title: WAP to generate consecutive NRPS & length n array, k distinct characters
Date : 22/11/19
Author : Shubhi omar
Description : Input : Enter value of n:
                      6
                      Enter value of k:
                      3
                      Enter k distinct characters:
                      abd
             Output : abdbda
 */
#include<stdio.h>
#include<stdlib.h>

//Function declaration
void NRPS_str(char str[], int len, int k);

int main()
{
    //Declaring local variables
    int n, k;
    int count, count1;
    char ch;
    char str[255];

    do
    {
	//Read input from user
	printf("Enter value of n:\n");
	scanf("%d", &n);

	printf("Enter value of k:\n");
	scanf("%d", &k);

	//Input validation
	if ((k < 1) || (k > 10))
	{
	    printf("Error:Invalid input\n");
	    return 1;
	}

	printf("Enter k distinct characters:\n");
	for (count = 0; count < k; count++)
	{
	    scanf("\n%c", &str[count]);
	}
	//Loop to check distinct characters
	for (count = 0; count < k; count++)
	{
	    for (count1 = (count+1); count1 < k; count1++)
	    {
		if (str[count1] == str[count])
		{
		    printf("Error: values are not distinct.\n");
		    return 1;
		}
	    }
	}

	//Call function to non - repetative patterns
	NRPS_str(str,n,k);

	printf("Continue(y/n):\n");
	scanf("\n%c", &ch);

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

//Function to non-repetative patterns
void NRPS_str(char str[] , int len, int k)
{
    int i, val = 0;

    for (i = 0; i < len; i++)
    {
	if((i % k) == 0 && i != 0)
	{
	    val++;
	}
	printf("%c", *(str + ((i+val) % k)));
    }
}
