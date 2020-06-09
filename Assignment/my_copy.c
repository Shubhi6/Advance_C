/*
   Title-:WAP for the prime no upto given limit.
   Author-:Shubhi omar
   Date-:25/09/2019
   Description-:Input-: Read a limit no from user.
   Output-:

 */

#include<stdio.h>
#include<stdlib.h>

//fun declartion
void my_copy(FILE *src_ptr,FILE *dest_ptr);

int main(int argc,char *argv[])
{      
        //declaration of variable
	FILE *src_ptr;
        FILE *dest_ptr;
       
        //validation for condition of cla
	if (argc < 3)
	{
		fprintf(stderr,"Error:give both file names");
		return 0;
	}
        //open source file for reading
	src_ptr =fopen(argv[1],"r");

        //checking if source file is empty or not
	if (src_ptr == NULL)
	{
		fprintf(stderr,"can't open file:%s\n",argv[1]);
		return 0;
	}
        
        //open dest file for writing
	dest_ptr =fopen(argv[2],"w");
        //for checking the contnt of file
	if (dest_ptr == NULL)
	{
		fprintf(stderr,"can't open file:%s\n",argv[2]);
		return 0;
	}
        
        //fun calling
	my_copy(src_ptr,dest_ptr);
        
        //for closing the file
	fclose(src_ptr);
	fclose(dest_ptr);
	return 0;
}

//fun definition
void my_copy(FILE *src_ptr,FILE *dest_ptr)
{      
        //declaration of varible
	char ch;
        //take all the word from source file
	while((ch =fgetc(src_ptr)) != EOF)
	{       
                //for putting the char to dest file
		fputc(ch,dest_ptr);
	}
}
