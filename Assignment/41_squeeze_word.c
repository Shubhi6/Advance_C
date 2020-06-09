/*
Title-:WAP to generate fibbonacci series less then the given no.
Author-:Shubhi omar
Date-:25/09/2019
Description-:Input-: Read two strings from user.
             Output-:Enter first string:
                      dennis ritchie
                     Enter second sting:
		     linux
                     new string is:des rtche


*/





#include<stdio.h>
#include<string.h>
#define MAXLINE 1000
//fun declaration
int get_line(char s[],int length);
void squeeze(char s1[],char s2[]);

int main()
{      
        //declaration of variable
	char s1[MAXLINE],s2[MAXLINE];
        // take string from use5r
	printf("Enter first string:\n ");
        //calling the fun for taking line
	get_line(s1,MAXLINE);
	printf("Enter second sting:\n");
	get_line(s2,MAXLINE);
        //calling the function
	squeeze(s1,s2);
	printf("new string is:%s\n",s1);
	return 0;
}

//fun definition
int get_line(char s[],int length)
{       
        //declartion of variable
	int c,i;
	//ifor loop 
	for(i=0; i < length - 1 && (c=getchar()) != EOF && c != '\n';i++)
	{
		s[i] = c;
	}
        // for taking the new line
	if (c == '\n')
	{
		s[i++] = c;
	}
	s[i]='\0';
}


//function definition
void squeeze(char s1[],char s2[])
{       
        // declaration of variable
	int i,j,k=0;
        //for loop for takinh character
	for (i=0;s1[i]!='\0';++i)
	{       
                //for loop for comparison both string
		for(j=0;(s1[i] != s2[j]) && s2[j]!='\0';++j);
                // for checking string 2
		if (s2[j] == '\0')
		{      // skip the char
			s1[k++] = s1[i];
		}
	}
	s1[k]='\0';
}
