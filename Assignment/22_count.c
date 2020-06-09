/*
Title-:WAP for the word ,character and lines counting..
Author-:Shubhi omar
Date-:25/09/2019
Description-:Input-: Read input given by user.
             Output-:./count.out 
                    Please enter the word to count:
                    we are programmer.
                    lines = 1
                    words = 3
                    characters = 19



 */









#include<stdio.h>

int main()
{
	int c,lines=0, words=0, new_char=0,flag=0;
	char option;

	do
	{

		printf("Please enter the word to count:\n");

		//for taking characters to the end of file 
		while((c= getchar()) != EOF)
		{
			++new_char;
			//for the new line
			if( c == '\n')
			{
				++lines;
			}
			//for the word taking condition of space,tab and new line
			if(c ==' ' || c == '\n' || c== '\t')
			{
				flag=0;
			}
			else if( flag == 0)
			{
				flag=1;
				++words;
			}
		}
		printf("lines = %d\nwords = %d\ncharacters = %d\n", lines,words,new_char);

		//for continue
		printf("continue(y/n):");
		scanf("%c",&option);
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
