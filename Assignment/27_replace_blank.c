/*
Title-:WAP for replace the more then one  blank in the line.
Author-:Shubhi omar
Date-:25/09/2019
Description-:Input-: Read a  character from user.
             Output-hi    how    are    you?
                    hi how are you?


*/






#include<stdio.h>
//fun declaration
void remove_blank(char *word);
int main()
{
	char option;
	do
	{       
		//taking no in buffer
		char s[255]={0};
		//take input from user
		printf("Enter the word with more then one spaces:\n");
               
                //function call
                remove_blank(s);
	        //printf("word after removing space:%s\n",s);
		printf("continue(y/n):");
		scanf("\n%c",&option);
                //loop for continue
		if (option == 'y')
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


void remove_blank (char *word)
{
	int c,last_char;
	char s[255]={0};
        
	//for end of the file
	while((c =getchar())!= EOF)
	{       
		//condition if character is space
		if(c == ' ')
		{        
			//if last character is not space
			if (last_char != ' ')
			{       
				//put same cahacter
				putchar(c);
			}
		} 
		else
		{
			putchar(c);
		}
		//for last character
		last_char= c;
	}
}
