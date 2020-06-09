/*
Title-:WAP to generate fibbonacci series less then the given no.
Author-:Shubhi omar
Date-:25/09/2019
Description-:Input-: Read  string from user.
             Output-:./string_combination.out 
Enter a string:abc
Combination of string:
abc
acb
bac
bca
cba
cab
*/




#include<stdio.h>
#include<string.h>
// declaration of fun
void swap(char*,char*);
void comb(char*,int,int);

int main()
{
       //declaration of variable
	char str[255],option;
	int length,start=0;
       do
       {
        //taking input from user
	printf("Enter a string:");
	scanf("%s",str);
        length = strlen(str);
        //for printing combiation
	printf("Combination of string:\n");
        //for calling of fun 
	comb(str,start,length -1);
	getchar();
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
}


//fun definition
void swap(char *p,char *q)
{       
        //declaration of variable
	char temp;
        //swapping concept
	temp = *p;
	*p =*q;
	*q = temp;
}


//fun definition
void comb(char *str,int i,int length)
{
        //declaration of variable
	int j;
        /*  if ( i == (length -1))
        {
         printf("Error!!");
        } */
        //if starting anf ending is same
        if (i == length)
	{
		printf("%s\n",str);
	}
       
	else
	{       // for loop till end 
                for(j = i;j<= length;j++)
		{       
                        //swapping fun call
			swap((str +i),(str +j));
                        //recursive calling of combination
			comb(str,i+1,length);
                        //again swapping
			swap((str +i),(str +j));
		}
	}
}
