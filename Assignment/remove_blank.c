/*
Title-:WAP for replace the more then one  blank in the line.
Author-:Shubhi omar
Date-:25/09/2019
Description-:Input-: Read a  character from user.
             Output-hi    how    are    you?
                    hi how are you?


*/







#include<stdio.h>

int main()
{       
        //defining variable
	int character ,last_character;
        
        //if last character is not new line
	if (last_character != '\n' )
	{       
               // loop for end of file
		while((character = getchar()) != EOF)
		{       
                       //condition if character is space
			if(character == ' ')
			{        
                                //if last character is not space
				if (last_character != ' ')
				{       
                                         //put same cahacter
					putchar(character);
				}
			} 
			else
			{
				putchar(character);
			}
			last_character= character;
		}
		return 0;
	}
}
