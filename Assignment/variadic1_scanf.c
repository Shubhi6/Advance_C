/*
Title:- Write a program to implement my_scanf() function
Author:- Shubhi Omar
Date:- 13/11/19
Description:- Input: 1.Read_int
                     2.Read_char
                     3.Read_string
                     choice option : 1
                     Enter the number : 12
                     Output: you entered number is = 12
             
 */

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include<string.h>


// function protocall
void scan_char(char *cptr);
void scan_int(int *dptr);
void scan_str(char *sptr);
int my_scanf(char *fmt, ...);

int main()
{
    // variable declaration
    int i,option;
    char ch, user_input = 'y';
    char ss[100];

    while (user_input == 'y')
    {

	// prompt to user which operation they want
	printf(" 1.Read_int\n 2.Read_char\n 3.Read_string\n");
	printf("choice option : ");
	scanf("%d",&option);
	switch (option)
	{
	    // case 1 for Read integer number
	    case 1:

		// prompt to user to enter the number and read that number
		printf("Enter the number : ");
	
                scanf("\n");
		// calling my scanf function and print the result
		my_scanf("%d",&i);
		printf("you entered number is = %d\n",i);
		break;

	    case 2:

		// case 2 for Read character

		// prompt user to enter the character
		printf("Enter the character : ");
		scanf("\n");

		//calling my scanf function and  print the result
		my_scanf("%c",&ch);
		printf("You enered character is = %c\n",ch);
		break;

	    case 3:

		

		// prompt user to enter the string without spaces
		printf("Enter the string : ");
		scanf("\n");

		// calling the my scanf function  and print that string
		my_scanf("%s",ss);
		printf("Enter string is = %s\n",ss);
		break;

	    default :
		// default case for entered wrong option
		printf("invaild input\n");

	}

	// prompt to user to continue again
	printf("Do you want to continue again [y/n] : ");
	scanf(" %c",&user_input);
    }
    return 0;
}

//Function declaration
int my_scanf(char *format, ...)
{

    va_list ap;

    // intialize all pointer to null
    int *d_ptr = NULL;
    char *c_ptr = NULL;
    char *s_ptr = NULL;
    char *ptr;

    /* Initialize the arg list */
    va_start(ap, format);

    for (ptr = format; *ptr; ptr++)
    {
	// checkinfg the format with argument type
	if (*format == '%')
	{
	    format++;

	    // checking the format with null character
	    if (*format == '\0')
	    {

		printf("Error: %% Invalid format specifier\n");
                exit(1);

	    }

	    // logic for read integer
            if ( *format == 'd')
            {
                d_ptr = va_arg(ap, int *);

		// calling scan int function
                scan_int(d_ptr);

		// checking next argument
                format++;
            }

	    // logic for read character
            if ( *format == 'c')
            {

                c_ptr = va_arg(ap, char *);

		// calling scan char function
                scan_char(c_ptr);

		// checking next argument
                format++;
            }

	    // logic for read string
            if ( *format == 's')
            {
                s_ptr = va_arg(ap, char *);

		//calling scan str function
                scan_str(s_ptr);

		//checking the next argument
                format++;
            }
            else
            {
                format++;
            }
        }
    }

    // closing the va end list
    va_end(ap);
}

// function for scan character
void scan_char(char *cptr)
{
    *cptr = getchar();
}

//function for scan int
void scan_int(int *dptr)
{
    // intialize the variable
    char arr1[100];
    int ch = 0;
    int i;

    // read input and store in ch
    ch = getchar();

    // read the data from stdin till it reaches space, tab or newline and save that into a arr1
    for (i = 0; ((ch != ' ') && (ch != '\t') && (ch != '\n')) ; i++)
    {

        arr1[i] = ch;
        ch = getchar();
    }

    /* return intger value into obtained address */
    *dptr = atoi(arr1);

}

// function for scan string
void scan_str(char *sptr)
{
    // variable declaration
    char arr2[100];
    int ch = 0;
    int i;

    // read input and store in ch
    ch = getchar();

    //read the data from stdin till it reaches space,  tab or newline and save that into a arr2
    for (i = 0; ((ch != ' ') && (ch != '\t') && (ch != '\n')) ; i++)
    {
        arr2[i] = ch;
        ch = getchar();
    }

    // assigning the null character to string
    arr2[i] = '\0';

    /* return intger value into obtained address */
    strcpy(sptr, arr2);

}
