/*
Title : WAP to average in 3 diffrent ways.
Date  : 22/11/2019
Author : Shubhi Omar
Description : Input :./a.out 4 5 6 7
                     1.Read input from user
                     2.Read input from CLA
                     3.Read input from enviorment variables
                     Enter the choice:
                     2
             Output : Avg = 5.500000
	     */

#include<stdio.h>
#include<stdlib.h>

//Function declarations
char *my_strtok (char *str, char *delim);
int my_atoi (char *num);

int main(int argc, char *argv[], char *envp[])
{
    //Declaring local variables
    int size, sum = 0,count = 0, num;
    float avg;
    int ary[count];
    int ch;

    if (argv[1] != 0)
    {

	printf("1.Read input from user\n2.Read input from CLA\n3.Read input from enviorment variables\n");
	printf("Enter the choice:\n");
	scanf("%d", &ch);

	if (ch == 1)
	{

	    //Read input from user
	    printf("Enter the number of elements:\n");
	    scanf("%d", &size);
	    int arr[size];
	    printf("Enter the numbers:\n");

	    for (count = 0; count < size; count++)
	    {
		scanf("%d", &arr[count]);
	    }
	    for (count = 0; count < size; count++)
	    {
		printf("arr[%d] = %d\n", count, arr[count]);
	    }
	    //Loop to sum of array of elements
	    for (count = 0; count < size; count++)
	    {
		sum = sum + arr[count];
	    }
	    //Calculate average
	    avg = (float) sum / size;
	    printf("Average = %lf\n", avg);
	}
	else if (ch == 2)
	{

	    for (count = 1; count < argc; count++)
	    {
		//Call function to convert ASCII to integer
		num = my_atoi(argv[count]);
		sum = sum + num;
	    }
	    //Calculate average
	    avg = (float) sum / (argc - 1);
	    printf("Avg = %f\n", avg);
	}
    }

    if (ch == 3)

    {
	//Read input as enviornment variable
	char *str = getenv("arr");
	printf("%s\n", str);
	//Call function to string tokens
	char *token = my_strtok(str, " ");
	while(token != NULL)
	{
	    printf("%s\n", token);
	    count++;
	    //Call function convert ASCII to integer
	    ary[count] = my_atoi(token);
	    sum = sum + ary[count];
	    token = my_strtok(NULL, " ");
	}
	//Calculate average
	avg = (float) sum / count;
	printf("Avg = %f\n", avg);
    }
    return 0;
}

//Function convert ASII to integer
int my_atoi (char *num)
{
    int count = 0, sign = 1, res = 0;
    //Check to minus sign
    if (num[count] == '-')
    {
	sign = -1;
	count++;
    }

    //Check to characters are digits
    while (num[count] >= '0' && num[count] <= '9')
    {
	//Convert ASCII to integer value
	res = res * 10 + num[count] - '0';
	count++;
    }     return (res * sign);
}
//Function to string tokens
char *my_strtok (char *str, char *delim)
{
    static int pos = 0;
    static char *str1;
    int count = 0, start = pos;

    if (str != NULL)
          str1 = str;
 
     while (str1[pos] != '\0')
     {
 
          //Loop to delimiter
          for (count = 0;delim[count] != '\0';count++)
          {
              if (str1[pos] == delim[count])
             {
                 str1[pos] = '\0';
                  pos = pos + 1;
 
                  if (str1[start] != '\0')
                      return (&str1[start]);
                 else
                 {
                      start = pos;
                     pos--;
                      break;
                  }
             }
 
         }
         pos++;
     }
     str1[pos] = '\0';
    if (str1[start] == '\0')
         return NULL;
    else
        return (&str1[start]);
 }
      
		    

	    


