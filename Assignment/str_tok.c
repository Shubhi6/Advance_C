/*
Title-:WAP for the bitwise operations.
Author-:Shubhi omar
Date-:25/09/2019
Description-:Input-: Read a  no and choice from user and the no of bits to shift
             Output-: 


 */
#include<stdio.h>
#include<stdlib.h>
//fun declaration
char* my_strtok(char*,char*);

int main()
{       
        //declaration of varible
	char  *token,str1[255],str2[255],option;
	int length=0;
	do
	{      
               //take input from user
		printf("Enter string with delimeter:\n ");
		__fpurge(stdin);
		scanf("%[^\n]",str1);
		printf("Enter delimeter:");
		__fpurge(stdin);
		scanf("%[^\n]",str2);
                //condition
		while(length++ != '\0');
                //fun call
		token=my_strtok(str1,str2);
                 //condition for token
		while(token != NULL)
		{
			printf("%s\n",token);
			token=my_strtok(NULL,str2);
		}

                //for continuation
		printf("Continue(y/n):");
		scanf("\n%c",&option);
		if(option == 'y')
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

//fun definiton
char* my_strtok(char *str,char *del)
{       
	//declaration of varible
	static int pos = 0;
	static char *s;
	int j,start;

	start =pos;
	//condition for checking null
	if( str != NULL)
	{
		s=str;
	}

	//till posiion is not null
	while(s[pos] != '\0')      
	{      //loop
		for(j=0;del[j]!='\0';j++)
		{       
			//condition for delimeter
			if (s[pos] == del[j])
			{ 
				s[pos] ='\0';
				//increase position
				pos = pos + 1;
				//condition for null
				if (s[start] !='\0')
				{
					return (&s[start]);
				}
				else 
				{      
					//if not null
					start = pos;
					pos--;
					break;
				} 
			}
		}
		pos++;
	}

	s[pos] ='\0';
	//condition for null
	if(s[start] == '\0')
	{
		return NULL;
	}
	else
	{      
		//address return
		return (&s[start]);
	}
}

