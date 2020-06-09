/*
Title-:WAP to generate fibbonacci series less then the given no.
Author-:Shubhi omar
Date-:25/09/2019
Description-:Input-: Read a no.
             Output-:Print fibbonacci series.

*/




#include<stdio.h>
#include<string.h>

//fun declaration
char *get_word(char *);
int atoi(char *str);
char *itoa (int,char*str);


int main()
{
        //declaration of variable
	int num,val,choice;
	char str[1000];
	char ch,word[1000],option;
        
        do
        {
        //take input from user
	printf("Enter the choice:\n1.get_word\n2.atoi\n3.itoa\n");
	scanf("%d",&choice);
        
        //switch case for choice
	switch(choice)
	{
		case 1:
                        //taking info from user
			printf("Enter the word");
			scanf("\n%[^\n]",&word);
                        
                        //calling the fun
			printf("Get word = %s\n",get_word(word));
			printf("Length = %ld\n",strlen(word));
			break;

		case 2:
                        //taking info from user
			printf("Enter the string:");
			scanf("%s",word);
                        
                        //fun calling
                        val = atoi(word);
			printf("string to integer =%d\n",val);
			break;

		case 3:
                        //taking info from user
			printf("Enter the number:\n");
			scanf("%d",&num);
                        //fun calling
			printf("Integer to string:%s\n",itoa(num,str));
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
}



//fun definition
char *get_word(char *word)
{       
        //declaration of varible
	int count1 = 0;
        
        //loop for end of word
	for(int count = 0; word[count] != '\0';count++)
	{       
                //condition for space
		if (word[count] == ' ')
		{
			word[count] = '\0';
			count1++;
		}
		else
		{
			word[count1] = word[count];
			count1++;
		}
	}
	return word;
}



//fun definition
int atoi (char *num)
{       
        //declartion of varible
	int count = 0,sign = 1,res =0;
        
        //condition for negative sign
	if (num[count] == '-')
	{
		sign = -1;
		count++;
	}
        
        //loop for the numbers
	while(num[count] >= '0' && num[count] <= '9')
	{       
                //condition for conversion
		res = res * 10 + num[count] - '0';
		count++;
	}
	return (res * sign);
}



//fun definition
char *itoa(int num,char *str)
{       
        //declaration of variable   
	int count = 0,sign;
        
        //checking for number
	if ((sign = num) < 0)
	{
		num = -num;
	}

	do
	{
          //for the digit   
	  str[count++] = (num % 10) + '0';

	}while((num = num / 10) > 0);
        
         //for negative sign
	if (sign < 0)
	{
		str[count++] = '-';
	}

	str[count] = '\0';
	int count1,count2;
	char ch;
        
        //for reversing the no
	for(count2 = 0, count1 = count -1;count2 <= count1; count2++, count1--)
	{
		ch = str[count2];
		str[count2] = str[count1];
		str[count1] = ch;
	}
	return str;
}



