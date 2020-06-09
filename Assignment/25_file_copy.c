/*
Title : WAP to my_copy function to copy one file contents to another file
Date : 22/11/19
Author : Sahana H S
Description: Input  : ./a.out 
                      Hello world
             Output : Hello world
*/	     

#include <stdio.h>
#include<stdlib.h>

//Function declaration
void my_copy(FILE *src_ptr, FILE *dest_ptr);

int main(int argc, char* argv[])
{
    //Declaring File pointers 
    FILE *f1ptr, *f2ptr, *f3ptr;

    if (argc == 1)
    {
	//Call function to copy contents
	my_copy(stdin,stdout);
    }
    else if (argc == 3)
    {
	//Statement to read file
	f1ptr = fopen(argv[1], "r");
	//Check file present or not
	if (f1ptr == NULL)
	{
	    printf("file1 fopen");
	    return -1;
	}
	f2ptr = fopen(argv[2], "r");
	if (f2ptr == NULL)
	{
	    perror("file2 fopen");
	    fclose(f1ptr); 
	    return -1;
	}
	//Call function to copy contents
	my_copy(f1ptr, stdout);
	my_copy(f2ptr, stdout);
    }
    else if (argc == 4)
    {
	f1ptr = fopen(argv[1], "r");
	if (f1ptr == NULL)
	{
	    printf("file1 fopen");
	    return -1;
	}

	f2ptr = fopen(argv[2], "r");
	if (f2ptr == NULL)
	{
	    printf("file2 fopen");
	    fclose(f1ptr);
	    return -1;
	}

	//Statement to Write file
	f3ptr = fopen(argv[3], "w+");
	if (f3ptr == NULL)
	{
	    printf("file3 fopen");
	    //Close file
	    fclose(f2ptr);
	    fclose(f1ptr);
	    return -1;
	}

	//Call function to copy contents
	my_copy(f1ptr, f3ptr);
	my_copy(f2ptr, f3ptr);

	fclose(f1ptr);
	fclose(f2ptr);
	fclose(f3ptr);
    }
}
//Function to copy contents
void my_copy(FILE *src_ptr, FILE *dest_ptr)
{
    char ch;

    while((ch = fgetc(src_ptr)) != EOF)
	fputc(ch,dest_ptr);
}

